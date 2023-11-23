#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;
/*
https://leetcode.com/problems/number-of-islands

Solution1. DSF inorder. Mark visited in place
time: o(n)
space: o(1)

Solution2. BSF. Mark visited in place
time: o(n)
space: o(1)

*/
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n1 = grid.size();
        int n2 = grid[0].size();

        if (i < 0 || i >= n1 || j < 0 || j >= n2 || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);

    }

    int numIslands_1(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == '0') continue;
                cnt++;
                dfs(grid, i, j);
            }
        }
        return cnt;
    }

    int numIslands_2(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int n1 = grid.size();
        int n2 = grid[0].size();

        int cnt = 0;
        for (int i=0; i<n1; ++i) {
            for (int j=0; j<n2; ++j) {
                if (grid[i][j] == '0') continue;

                cnt++;
                queue<pair<int,int>> q;
                q.push({i, j});
                
                while (!q.empty()) {
                    int qSize = q.size();
                    for (int k=0; k<qSize; ++k) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        
                        if (row < 0 || row >= n1 || col < 0 || col >= n2) continue;
                        if (grid[row][col] == '0') continue;

                        grid[row][col] = '0';
                        q.push({row-1, col});
                        q.push({row+1, col});
                        q.push({row, col-1});
                        q.push({row, col+1});
                    }
                }
            }
        }
        return cnt;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        return numIslands_2(grid);
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