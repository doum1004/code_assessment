#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/critical-connections-in-a-network/

//Solution1. Bridge find. Simular like Tajan for articution point
https://leetcode.com/problems/critical-connections-in-a-network/discuss/389841/C%2B%2B-tarjon-clear-solution
https://www.youtube.com/watch?v=2kREIkF9UAs
https://www.youtube.com/watch?v=jFZsDDB0-vo
//time: o(v+e). visit(v+e)
//space: o(v+e). graph(e+v) low(v) discovery(v)

// build graph
// DSF from root to build discovery and low(min(dist[cur], dist[adj]) table.
// if discovery[cur] < low[adj] : articulation edge (cur,adj)

1. build graph
2. BFS from random node. Here from 0
2.1. It takes cur, and parent
2.2. Increase time. store time on cur dist and low of dist
2.3. visit adjs
2.3.1. skip if adj is parent
2.3.2. visit adj
2.3.3. update low[cur] with dist[adj]
2.3.4. if dist[cur] < low[adj]: it is articulation point. add edge on res

*/

class Solution {
    vector<vector<int>> g, res;
    vector<int> dist, low;
    int time;
    
    void dfs(int cur, int parent) {
        if (dist[cur] > 0) return;
        time++;
        dist[cur] = low[cur] = time;
        for (auto &adj:g[cur]) {
            if (adj == parent) continue;
            dfs(adj, cur);
            low[cur] = min(low[cur], low[adj]);
            if (dist[cur] < low[adj]) res.push_back({cur, adj});
        }
    }
    
public:
    vector<vector<int>> criticalConnections_tajan(int n, vector<vector<int>>& connections) {
        dist.resize(n);
        low.resize(n);
        g.resize(n);
        
        for (auto &c:connections) {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        dfs(0,-1);
        return res;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        return criticalConnections_tajan(n, connections);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{0,1},{1,2},{2,0},{1,3}};
    auto output1 = vector<vector<int>> {{1,3}};
    assert(Solution().criticalConnections(4, input1) == (output1));

    auto input2 = vector<vector<int>> {{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3}};
    auto output2 = vector<vector<int>> {{1,3}};
    assert(Solution().criticalConnections(6, input2) == (output2));

    auto input3 = vector<vector<int>> {{1,0},{2,0},{3,2},{4,2},{4,3},{3,0},{4,0}};
    auto output3 = vector<vector<int>> {{0,1}};
    assert(Solution().criticalConnections(5, input3) == (output3));
    
    return 0;
}