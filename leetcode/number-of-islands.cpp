#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/number-of-islands/

// 11110
// 11010
// 11000
// 00000

// vector<vector<char>> grid
// find unvisited '1' and visit all adjacents and mark as visited
// 1 -> 0 I don't need extra space
// graph DFS serach
// time: o(row * col)
// space: o(row * col) recursion

// BFS
// using queue<pair<int, int>>
// time: o(m+n)
// space: o(min(m,n)) can go futher
// offset[] = {0, 1, 0, -1, 0}
// for
//   for
//     if ([i][j] == '1')
//       [][] = '0'
//       queue<pair<int, int>> q
//       q.push(i,j)
//       while (!q.empty())
//         auto p = q.front()
//         q.pop()
//         for (int k=0; i<4; k++)
//           r = p.first + offset[k]
//           c = p.second + offset[k+1]
//           if (r >= 0 && r <size .... grid[i][j] == '1')
//              grid[r][c] = '0'
//              q.push({r,c});

class Solution {
public:
    int numIslands_DFS(vector<vector<char>>& grid) {
        if (grid.size() < 1 || grid[0].size() < 1) return 0;

        int n_r = grid.size();
        int n_c = grid[0].size();
        int count = 0;

        for (int i=0; i<n_r; ++i) {
            for (int j=0; j<n_c; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    visitIsland(grid, i, j);
                }
            }
        }

        return count;
    }

    int numIslands_BFS(vector<vector<char>>& grid) {
        if (grid.size() < 1 || grid[0].size() < 1) return 0;
        auto n_r = grid.size();
        auto n_c = grid[0].size();
        int offset[] = {0, 1, 0, -1, 0};

        auto count = 0;
        for (int i=0; i<n_r; ++i) {
            for (int j=0; j<n_c; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    grid[i][j] = '0';
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        for (auto k=0; k<4; ++k) {
                            auto r = p.first + offset[k];
                            auto c = p.second + offset[k+1];
                            if (r >= 0 && r<n_r && c >= 0 && c<n_c && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                q.push({r,c});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }

    int numIslands(vector<vector<char>>& grid) {
        //return numIslands_DFS(grid);
        return numIslands_BFS(grid);
    }

private:
    void visitIsland(vector<vector<char>>& grid, int i, int j) {
        int n_r = grid.size();
        int n_c = grid[0].size();
        if (i < 0 || i >= n_r || j < 0 || j >= n_c || grid[i][j] == '0') return;

        grid[i][j] = '0';
        visitIsland(grid, i-1, j);
        visitIsland(grid, i, j-1);
        visitIsland(grid, i, j+1);
        visitIsland(grid, i+1, j);
    }
};

int main()
{
    auto input1 = vector<vector<char>>();
    input1.push_back(vector<char>{'1', '1', '1', '1', '0'});
    input1.push_back(vector<char>{'1', '1', '0', '1', '0'});
    input1.push_back(vector<char>{'1', '1', '0', '0', '0'});
    input1.push_back(vector<char>{'0', '0', '0', '0', '0'});
    assert(Solution().numIslands(input1) == 1);
   
    auto input2 = vector<vector<char>>();
    input2.push_back(vector<char>{'1'});
    input2.push_back(vector<char>{'1'});
    assert(Solution().numIslands(input2) == 1);

    auto input3 = vector<vector<char>>();
    input3.push_back(vector<char>{'1', '1', '0', '0', '0'});
    input3.push_back(vector<char>{'1', '1', '0', '0', '0'});
    input3.push_back(vector<char>{'0', '0', '1', '0', '0'});
    input3.push_back(vector<char>{'0', '0', '0', '1', '1'});
    assert(Solution().numIslands(input3) == 3);

    return 0;
}