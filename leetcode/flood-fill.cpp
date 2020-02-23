#include <iostream>
#include <cassert>

#include <vector>
#include <queue>

using namespace std;

/**
https://leetcode.com/problems/flood-fill/

1 1 1
1 1 0
1 0 1

2 2 2
2 2 0
2 0 1

// solution1. DSF preorder recursion
// time: o(n) visiting connected
// space: o(n) recursion. visited

1. recursion from sr, sc
2. check input validation with visitied status. and mark visited and set new color. and visit adjacent nodes

// soluiton2. BSF iteration with queue
// time: o(n)
// space: o(n). queue, visited

1. put sr, sc in queue
2. iterate queue. put visited and set new color. and put adjacent nodes in queue.

1. 

*/

class Solution {
public:
    int offset[5] = {0,1,0,-1,0};
    void bdsf_recursion(vector<vector<int>>& image, vector<vector<bool>>& visited, int r, int c, int reference, int newColor) {
        if (r<0 || c<0 || r>=image.size() || c>=image[0].size() || image[r][c] != reference || visited[r][c] == true) return;
        
        visited[r][c] = true;
        image[r][c] = newColor;
        
        for (int i=0; i<=3; ++i) {
            bdsf_recursion(image, visited, r+offset[i], c+offset[i+1], reference, newColor);
        }
    }
    
    vector<vector<int>> floodFill_dsf_recursion(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() < 1 || image[0].size() < 1 || sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return image;
        
        vector<vector<bool>> v(image.size(), vector<bool>(image[0].size(), false));
        bdsf_recursion(image, v, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    vector<vector<int>> floodFill_bsf_iteration(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() < 1 || image[0].size() < 1 || sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return image;
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        auto reference = image[sr][sc];
        vector<vector<bool>> v(image.size(), vector<bool>(image[0].size(), false));
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            auto r = node.first;
            auto c = node.second;
            if (r<0 || c<0 || r>=image.size() || c>=image[0].size() || image[r][c] != reference || v[r][c] == true) continue;

            v[r][c] = true;
            image[r][c] = newColor;

            for (int i=0; i<=3; ++i) {
                q.push({r+offset[i], c+offset[i+1]});
            }
        }
        
        return image;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //return floodFill_dsf_recursion(image, sr, sc, newColor);
        return floodFill_bsf_iteration(image, sr, sc, newColor);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{1,1,1},{1,1,0},{1,0,1}};
    auto expect1 = vector<vector<int>> {{2,2,2},{2,2,0},{2,0,1}};
    assert(Solution().floodFill(input1, 1, 1, 2) == (expect1));

    return 0;
}
