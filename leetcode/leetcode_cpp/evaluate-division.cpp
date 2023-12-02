#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
https://leetcode.com/problems/evaluate-division

Solution1. Build Graph and DFS to find acuumulate factor
time: o(e*q). build graph(e. equation) + (dfs(n) * queries(q))
space: o(e): graph

*/

class Solution {
public:
    double findFactor(unordered_map<string, unordered_map<string, double>>& h, const string& cur, const string& tar, unordered_set<string>& v, double factor) {
        if (cur == tar) return factor;
        if (v.count(cur)) return -1;
        v.insert(cur);
        
        for (auto &n:h[cur]) {
            auto result = findFactor(h, n.first, tar, v, factor * n.second);
            if (result != -1) return result;
        }
    
        return -1;
    }
    
    vector<double> calcEquation_graph_dfs(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> h;
        for (int i=0; i<equations.size(); ++i) {
            auto e = equations[i];
            auto v = values[i];
            h[e[0]][e[1]] = v;
            h[e[1]][e[0]] = 1/v;
        }
        
        vector<double> res;
        for (auto &q:queries) {
            double n = -1.0;
            if (h.count(q[0]) && h.count(q[1])) {
                if (h[q[0]].count(q[1])) {
                    n = h[q[0]][q[1]];
                }
                else {
                    unordered_set<string> v;
                    n = findFactor(h, q[0], q[1], v, 1);
                }
            }
            res.push_back(n);
        }
        return res;
    }
    
    double dfs(unordered_map<string, vector<pair<string,double>>>& graph, string start, string end, double product, unordered_set<string>& visited) {
        if (visited.count(start)) return -1;
        if (!graph.count(start) || !graph.count(end)) return -1;
        if (start == end) {
            return product;
        }

        visited.insert(start);
        for (auto& g : graph[start]) {
            auto ans = dfs(graph, g.first, end, product * g.second, visited);
            if (ans != -1)
                return ans;
        }
        visited.erase(start);
        return -1;
    }

    vector<double> calcEquation_1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        int m = queries.size();
        if (m == 0) return {};
        unordered_map<string, vector<pair<string,double>>> graph;
        for (int i=0; i<n; ++i) {
            auto& equation = equations[i];
            auto& e1 = equation[0];
            auto& e2 = equation[1];
            auto& v = values[i];
            graph[e1].push_back({e2, v});
            graph[e2].push_back({e1, 1.0/v});
        }
        
        vector<double> res;
        for (auto& query : queries) {
            auto& q1 = query[0];
            auto& q2 = query[1];
            unordered_set<string> visited;
            res.push_back(dfs(graph, q1, q2, 1, visited));            
        }
        return res;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //return calcEquation_graph_dfs(equations, values, queries);
        return calcEquation_1(equations, values, queries);
    }
};

int main()
{
    auto input1_1 = vector<vector<string>> {{"a", "b"}, {"b", "c"}};
    auto input1_2 = vector<double> {2.0, 3.0};
    auto input1_3 = vector<vector<string>> {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    assert(Solution().calcEquation(input1_1, input1_2, input1_3) == (vector<double>{6.0, 0.5, -1.0, 1.0, -1.0}));

    return 0;
}