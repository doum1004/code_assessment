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

solution 2. Dijkstra's algorithm
https://www.youtube.com/watch?v=XB4MIexjvY0
// time: o(n^n). visit(n)* relaxation(n. update vertiex)
// space: o(n)


solution 3. Bellman Ford
https://www.youtube.com/watch?v=FtN3BYH2Zes
// time: o(n^n). visit(n) * relaxation (n-1)
// space: o(n). table


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
        // build graph. g[u] = {v,w}
        vector<vector<pair<int,int>>> g(N);
        for (int i=0; i<times.size(); ++i) {
            int u = times[i][0]-1, v = times[i][1]-1, w = times[i][2];
            g[u].push_back({v,w});
        }
        
        // run dijkstra and get table
        auto ret = dijkstra(g, K-1);
        
        // get max delay
        int res = 0;
        for (auto &delay:ret) {
            if (delay == -1) return -1;
            res = max(res, delay);
        }
        
        return res;
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
            maxDelay = max(maxDelay, dist[i]);
        }
        return (maxDelay == INT_MAX) ? -1 : maxDelay;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //return networkDelayTime_dsf(times, N, K);
        //return networkDelayTime_dijkstra(times, N, K);
        return networkDelayTime_bellmanford(times, N, K);
    }
    
private:
    vector<int> dijkstra(vector<vector<pair<int,int>>>& g, int s){
        // build table
        int n = g.size();
        vector<int> table(n, -1);
        
        // min heap to take min delay for next candidate
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0, s});
        
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

        return table;
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{2,1,1},{2,3,1},{3,4,1}};
    assert(Solution().networkDelayTime(input1, 4, 2) == (2));
    return 0;
}