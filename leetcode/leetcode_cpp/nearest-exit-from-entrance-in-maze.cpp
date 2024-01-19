/*
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

1. BFS
time: o(n)
space: o(n)
*/
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<array<int, 3>> q;
        q.push({0, entrance[0], entrance[1]});

        while (!q.empty()){
            auto [step, posX, posY] = q.front(); q.pop();
            if (maze[posX][posY] != '.') continue;
            if (step != 0 && (posX == 0 || posY == 0 || posX == maze.size()-1 || posY == maze[0].size()-1)) return step;
            maze[posX][posY] = 'x';
            
            if (posX+1 < maze.size())
                q.push({step+1, posX + 1, posY});
            if (posX-1 >= 0)
                q.push({step+1, posX - 1, posY});
            if (posY+1 < maze[0].size())
                q.push({step+1, posX, posY+1});
            if (posY-1 >= 0)
                q.push({step+1, posX, posY-1});
        }

        return -1;
    }
};