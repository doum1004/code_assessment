#include <iostream>
#include <cassert>

#include <vector>
#include <queue>

using namespace std;

/**
https://leetcode.com/problems/flood-fill/

input
1 1 1 1  (1,1) 3
0 1 0 0
1 0 1 0

output
3 3 3 3
0 3 0 0
1 0 1 0

solution1 DFS recursion
// time: o(n). n=r*c
// space: o(n). n=r*c

from sr,sc. mark visited(new color could be marker)
def recursion(image, r, c, newColor)
#1 check r,c range and visited mark
#2 change color
#3 visit adjacents

solution2 BSF iteration with queue
// time: o(n)
// space: o(n)

*/

class Solution {
public:
    int offset[5] = {0,1,0,-1,0};
    void fillNewColor(vector<vector<int>>& image, int sr, int sc, int refColor, int newColor) {
        if (sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc] != refColor || image[sr][sc] == newColor) return;
        image[sr][sc] = newColor;
        for (int i=0; i<=3; ++i) fillNewColor(image, sr+offset[i], sc+offset[i+1], refColor, newColor);
    }
    
    vector<vector<int>> floodFill_dsf(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() < 1 || image[0].size() < 1 || sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return image;
        fillNewColor(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    vector<vector<int>> floodFill_bsf(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() < 1 || image[0].size() < 1 || sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return image;
        
        int refColor = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            auto r = node.first;
            auto c = node.second;
            if (r<0 || c<0 || r>=image.size() || c>=image[0].size() || image[r][c] != refColor || image[r][c] == newColor) continue;
            image[r][c] = newColor;
            
            for (int i=0; i<=3; ++i) {
                q.push({r+offset[i], c+offset[i+1]});
            }
        }
        
        
        return image;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //return floodFill_dsf(image, sr, sc, newColor);
        return floodFill_bsf(image, sr, sc, newColor);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{1,1,1},{1,1,0},{1,0,1}};
    auto expect1 = vector<vector<int>> {{2,2,2},{2,2,0},{2,0,1}};
    assert(Solution().floodFill(input1, 1, 1, 2) == (expect1));

    return 0;
}
