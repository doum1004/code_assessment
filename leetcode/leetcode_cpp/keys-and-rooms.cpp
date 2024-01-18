/*
https://leetcode.com/problems/keys-and-rooms

1. bfs (queue)
time: o(n)
space: o(n)
2. dfs
time: o(n)
space: o(n)
*/
class Solution {
public:
    bool canVisitAllRooms_bfs(vector<vector<int>>& rooms) {
        if (rooms.size() <= 1) return true;
        unordered_set<int> v;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (v.count(node)) continue;
            v.insert(node);
            for (int next : rooms[node]) {
                q.push(next);
            }
        }
        return v.size() == rooms.size();
    }

    void dfs(vector<vector<int>>& rooms, unordered_set<int>& v, int i) {
        if (v.count(i)) return;
        v.insert(i);
        for (int room : rooms[i]) {
            dfs(rooms, v, room);
        }
    }

    bool canVisitAllRooms_dfs(vector<vector<int>>& rooms) {
        if (rooms.size() <= 1) return true;
        unordered_set<int> v;
        dfs(rooms, v, 0);
        return v.size() == rooms.size();
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        return canVisitAllRooms_dfs(rooms);
    }
};