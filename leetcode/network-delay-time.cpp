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

solution 2. Dijkstra's algorithm (none negative)
https://www.youtube.com/watch?v=XB4MIexjvY0
// time: o(n^n). graph(E). visit(n)* relaxation(n-1. update vertiex)
// space: o(N+E). graph(E). table(N)


solution 3. Bellman Ford (negative, no cycle negative sum)
https://www.youtube.com/watch?v=FtN3BYH2Zes
// time: o(n^n)
// space: o(n)


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
    
    
    int networkDelayTime_(vector<vector<int>>& times, int N, int K) {
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
    
    int networkDelayTime_dijkstra(vector<vector<int>>& times, int N, int K) {
        // build graph
        vector<vector<pair<int,int>>> g(N+1);
        for (auto &e:times) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
        }        
        
        // dijkstra
        vector<int> table(N+1, -1);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0, K});
        
        while (!q.empty()) {
            auto delay = q.top().first;
            auto node = q.top().second;
            q.pop();
            
            if (table[node] != -1) continue;
            table[node] = delay;
            
            for (auto &adj:g[node]) {
                q.push({adj.second+delay, adj.first});
            }
        }
        
        // get maxDelay
        int maxDelay = 0;
        for (int i=1; i<=N; ++i) {
            if (table[i] == -1) return -1;
            maxDelay = max(maxDelay, table[i]);
        }
        
        return maxDelay;
    }
    
    int networkDelayTime_bellmanford(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N+1, INT_MAX);
        dist[K] = 0;
        for (int i=0; i<=N; ++i) {
            for (auto &e:times) {
                auto u=e[0], v=e[1], w=e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        int maxDelay = 0;
        for (int i=1; i<=N; ++i) {
            if (dist[i] == INT_MAX) return -1;
            maxDelay = max(maxDelay, dist[i]);
        }
        
        return maxDelay;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //return networkDelayTime_dsf(times, N, K);
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