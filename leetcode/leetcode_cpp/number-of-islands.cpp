#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/number-of-islands/submissions/

// DFS Recursion preorder
// time: o(n) : rows * colmn
// space: o(n) : rows * colmn
check all visit by DFS top, right, bottom, left
and move to next

11110
11010
11000
00000
(0,0) -> BFS preorder. visit and mark all nodes to the end

// BFS iteractive
// time: o(r*c)
// space: o(min(r,c)) : because queue can grow up to min(r,c)
iterate space
    if find land, push into queue
    iterate queue
        q: (0,0)
        q: (1,0), (1,0)
        q: (1,1), (2,0) (1,1) (0,2)
        q: (2,1), (0,3)
        q: (1,3)


**/

class Solution {
public:
    void checkLand(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') return;

        grid[row][col] = '0';
        checkLand(grid, row-1, col);
        checkLand(grid, row, col+1);
        checkLand(grid, row+1, col);
        checkLand(grid, row, col-1);
    }

    int numIslands_recursion_dfs(vector<vector<char>>& grid) {
        if (grid.size() < 1 || grid[0].size() < 1) return 0;
        int ans = 0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    checkLand(grid, i, j);
                }
            }
        }
        return ans;
    }

    int numIslands_iteration_bfs(vector<vector<char>>& grid) {
        if (grid.size() < 1 || grid[0].size() < 1) return 0;
        
        int offset[] = {0, 1, 0, -1, 0};
        auto n_r = grid.size();
        auto n_c = grid[0].size();
        
        int ans = 0;
        for (int i=0; i<n_r; ++i) {
            for (int j=0; j<n_c; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        
                        for (int k=0; k<4; ++k) {
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
        return ans;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        //return numIslands_recursion_dfs(grid);
        return numIslands_iteration_bfs(grid);
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