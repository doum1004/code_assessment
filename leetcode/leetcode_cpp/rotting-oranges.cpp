/*
https://leetcode.com/problems/rotting-oranges

1. BFS
time: o(n)
space: o(n)
- Add all rotten orange in queue
- Visit adj nodes and mark it. After loop of queue size, add day += 1
- Check again Fresh orange exist
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS
        queue<pair<int, int>> q;
        
        bool noFresh = true;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    noFresh = false;
            }
        }
        if (noFresh) return 0;
        if (q.empty()) return -1;

        int res = 0;
        while (!q.empty()) {
            int qSize = q.size();
            for (int k=0; k<qSize; ++k){
                int i = q.front().first, j = q.front().second; q.pop();
                if (i+1 < grid.size() && grid[i+1][j] == 1) {
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                }
                if (j+1 < grid[0].size() && grid[i][j+1] == 1) {
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                }
                if (i > 0 && grid[i-1][j] == 1) {
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                }
                if (j > 0 && grid[i][j-1] == 1) {
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                }
            }
            if (!q.empty()) res += 1;
        }
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return res;
    }
};