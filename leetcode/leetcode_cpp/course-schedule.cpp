#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/course-schedule/

// Solution1. BFS Iteration (Topological Sort). Kahn's algorithm. Not really BFS basically.
// time: o(V+E). V(vertices) E(Edges)
// space: o(V+E). graph(V+E) + indegree(V)

1. build graph and count indegree
2. BSF to to order indepedent to depedent

// Solution2. DFS recursion (Topological Sort) with visited and instack to detact cycle
// time: o(V+E). V(vertices) E(edges). graph(V+E). cycle check(V+E)
// space: o(V+E). graph(V+E) recursion(V+E)

1. save as directed graph
2. DFS recursion call on each node. add visited to skip. push and pop instack to detact cycle

*/

class Solution {
public:
    bool canFinish_BFS_Iteration(int numCourses, vector<vector<int>>& prerequisites) {
        // build graph & count indegree
        vector<unordered_set<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto &preq:prerequisites) {
            graph[preq[1]].insert(preq[0]);
            indegree[preq[0]]++;
        }
        
        vector<int> bfs;
        for (int i=0; i<numCourses; ++i) {
            if (indegree[i] == 0) bfs.push_back(i);
        }
        
        for (int i=0; i<bfs.size(); ++i) {
            for (auto &adj:graph[bfs[i]]) {
                if (--indegree[adj] == 0) bfs.push_back(adj);
            }
        }
        
        return bfs.size() == numCourses;
    }
    
    bool hasCycle(vector<vector<int>>& g, vector<bool>& v, unordered_set<int>& instack, int node) {
        if (instack.find(node) != instack.end()) return true;
        if (v[node]) return false;
        v[node] = true;
        instack.insert(node);
        for (auto &adj:g[node]) {
            if (hasCycle(g, v, instack, adj)) return true;
        }
        instack.erase(node);
        return false;
    }
    
    bool canFinish_DSF_recursion(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());            
        for (auto &p:prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        
        vector<bool> v(numCourses, false);
        for (auto &p:prerequisites) {
            unordered_set<int> instack;
            if (hasCycle(g, v, instack, p[0])) return false;
        }
        
        return true;
    }
    
    bool hasCycle(unordered_map<int, vector<int>>& g, unordered_set<int>& v, unordered_set<int>& innerV, int node) {
        if (innerV.count(node)) return true;
        if (v.count(node)) return false;
        v.insert(node);

        innerV.insert(node);
        for (auto& adj : g[node]) {
            if (hasCycle(g, v, innerV, adj)) return true;
        }
        innerV.erase(node);
        return false;
    }

    bool canFinish_1(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> g;
        for (auto& p:prerequisites)
            g[p[0]].push_back(p[1]);
        
        unordered_set<int> v;
        for (auto& p:prerequisites) {
            unordered_set<int> innerV;
            if (hasCycle(g, v, innerV, p[0])) return false;
        }
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return canFinish_BFS_Iteration(numCourses, prerequisites);
        //return canFinish_DSF_recursion(numCourses, prerequisites);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{1,0}};
    assert(Solution().canFinish(2, input1) == (true));
    auto input2 = vector<vector<int>> {{1,0},{0,1}};
    assert(Solution().canFinish(2, input2) == (false));
    return 0;
}