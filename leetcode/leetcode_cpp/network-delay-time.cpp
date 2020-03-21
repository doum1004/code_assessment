#include <iostream>
#include <cassert>
#include <algorithm> // max
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/**
https://leetcode.com/problems/network-delay-time/

solution 1. DSF preorder in recursion
time: o(ElogE + N^2). sort(ElogE) + visit node from node
space: o(E + N), E(all edges in graph), N(nodes in stack)

1. create a map to build graph from vector. and sort for speeding up.
2. start recursion from K (graph, map<int, int> receivedtime, node, delay). add delay.
3. check receivedtime and return max delay

solution 2. BSF
//time: o(E+ElogE+N^2). build graph(E edges) + sort(ElogE) + BSF(N^2. node)
//space: o(E+N). graph(E) queue(N)

1. build graph and sort for visiting small first
2. bsf to visit node using queue<node, time>. and check visited node time is smaller. and mark min visited time.

solution 3. Dijkstra's algorithm (none negative)
https://www.youtube.com/watch?v=XB4MIexjvY0
https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/
// time: o(n^2). graph(E). visit(n)*relaxation(n-1. update vertiex)
// space: o(V+E). graph(E). table(V)

solution 4. Bellman Ford (negative, no cycle negative sum)
https://www.youtube.com/watch?v=FtN3BYH2Zes
// time: o(n^3). graph(E). visit&update(V^3. (v*v-1)*v)
// space: o(V+E). graph(E). table(V)

*/

class Solution {
public:
    void sendSignal(unordered_map<int,vector<pair<int,int>>>& graph, unordered_map<int,int>& received, int node, int total_delay) {
        //cout << node << endl;
        if (total_delay >= received[node]) return;
        received[node] = total_delay;

        for (auto &adj:graph[node]) {
            sendSignal(graph, received, adj.second, adj.first + total_delay);
        }
    }
    
    
    int networkDelayTime_dsf(vector<vector<int>>& times, int N, int K) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for (auto &time:times) {
            graph[time[0]].push_back({time[2], time[1]});
        }
        
        for (auto &adjs:graph) {
            sort(adjs.second.begin(), adjs.second.end());
        }
        
        unordered_map<int,int> received;
        for (int i=1; i<=N; ++i) {
            received[i] = INT_MAX;
        }
        sendSignal(graph, received, K, 0);
    
        int maxSignal = -1;
        if (received.size() == N) {
            for (auto &node:received) {
                if (node.second == INT_MAX) return -1;
                maxSignal = max(maxSignal, node.second);
            }
        }
        return maxSignal;
    }
    
    int networkDelayTime_bsf(vector<vector<int>>& times, int N, int K) {
        // 1.
        unordered_map<int,vector<pair<int,int>>> g;
        for (auto &time:times) {
            g[time[0]].push_back({time[2], time[1]});
        }
        
        for (auto &n:g) {
            sort(n.second.begin(), n.second.end());
        }
        
        // 2.
        unordered_map<int, int> visited;
        for (int i=1; i<=N; ++i) {
            visited[i] = INT_MAX;
        }
        
        queue<pair<int,int>> q; // {node, time}
        q.push({K, 0});
        
        while (!q.empty()) {
            auto node = q.front().first;
            auto time = q.front().second;
            q.pop();
            
            if (visited[node] <= time) continue;
            visited[node] = time;
            
            for (auto &adj:g[node]) {
                q.push({adj.second, time+adj.first});
            }
        }
        
        int res = 0;
        for (auto &n:visited) {
            if (n.second == INT_MAX) return -1;
            if (n.first == K) continue;
            res = max(n.second, res);
        }
    
        return res;
    }

    int networkDelayTime_dijkstra(vector<vector<int>>& times, int N, int K) {
        // build graph
        unordered_map<int, vector<pair<int,int>>> g;
        for (auto &time:times) g[time[0]].push_back({time[2], time[1]});
        
        // time table
        vector<int> t(N+1, -1);
        
        // next node selection pool
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<void>> q;
        q.push({0, K});
        
        // visit and update time table
        while (!q.empty()) {
            auto time = q.top().first;
            auto node = q.top().second;
            q.pop();
            
            if (t[node] != -1 && t[node] <= time) continue;
            t[node] = time;
            
            for (auto &adj:g[node]) {
                q.push({time+adj.first, adj.second});
            }
        }
        
        // take final time
        int res = 0;
        for (int i=1; i<=N; ++i) {
            if (t[i] == -1) return -1;
            res = max(res, t[i]);
        }
        return res;
    }
    
    int networkDelayTime_bellmanford(vector<vector<int>>& times, int N, int K) {
        // build and update table
        vector<int> dist(N+1, INT_MAX);
        dist[K] = 0;
        for (int i=0; i<N-1; ++i) {
            bool changed = false;
            for (auto &time:times) {
                auto u=time[0], v=time[1], w=time[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    changed = true;
                }
            }
            if (!changed) break;
        }
        
        // find max
        int res = 0;
        for (int i=1; i<=N; ++i) {
            if (dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //return networkDelayTime_dsf(times, N, K);
        //return networkDelayTime_bsf(times, N, K);
        //return networkDelayTime_dijkstra(times, N, K);
        return networkDelayTime_bellmanford(times, N, K);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{2,1,1},{2,3,1},{3,4,1}};
    assert(Solution().networkDelayTime(input1, 4, 2) == (2));
    return 0;
}