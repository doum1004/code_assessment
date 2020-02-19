#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/spiral-matrix/

// Solution1. Iteration with queue and set(visiter)
// time: o(n)
// space: o(n) : set (visiter)

1. prepare visiter
2. prepare offset for next sprial check
3. iterate by queue. check visit and answer. Iterate offset to push next in queue

1 2  3  4
5 6  7  8
9 10 11 12

n(3), m(4)

r c
0 0 (0, 1)
0 1 (0, 1)
0 2 (0, 1)
0 3 (0, 1)
1 3 (1, 0)
2 3 (1, 0)
3 3 (1, 0)
3 2 (0, -1)
3 1 (0, -1)
3 0 (0, -1)
2 0 (-1, 0)
1 0 (-1, -1)
1 1 (0, 1)
...


// Solution2. Layer by layer
// time: o(n)
// space: o(1)
1. prepare pointers for index. Top, Bottom, Left, Right
2. Each iteration do top, right, bottom, left iteration

1 2  3  4
5 6  7  8
9 10 11 12

1) top=0, bottom=2, left=0, right=3. iterate top(left to right), right(top+1 to bottom), bottom(right-1 to left), left(bottom-1 to top+1)
2) top=1 bottom=1, left=1, right=2. iterate top, right, bottom, left
3) top=2 bottom=0, left=2, right=1. done

*/


class Solution {
public:
    vector<int> spiralOrder_map(vector<vector<int>>& matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return vector<int>();
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int offset[] = {0,1,0,-1,0};
        int last_offset_idx = 0;
        vector<int> ans;
        
        while (!q.empty()) {
            auto r = q.front().first;
            auto c = q.front().second;
            q.pop();
            v[r][c] = 1;
            ans.push_back(matrix[r][c]);
            
            for (int i=0; i<=3; ++i) {
                auto offset_idx = last_offset_idx + i;
                if (offset_idx >= 4) offset_idx = 0;
                last_offset_idx = offset_idx;
                
                auto new_r = r + offset[offset_idx];
                auto new_c = c + offset[offset_idx+1];
                if (new_r >= 0 && new_r <= n-1 && new_c >=0 && new_c <= m-1 && v[new_r][new_c] == 0) {
                    q.push({new_r, new_c});
                    break;
                }
            }
        }
        
        return ans;
    }
    
    vector<int> spiralOrder_layers(vector<vector<int>>& matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return vector<int>();
        
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, bottom = n-1, left = 0, right = m-1;
        vector<int> ans;
        while (top <= bottom && left <= right) {
            cout << "start";
            for (int c=left; c<=right; c++) ans.push_back(matrix[top][c]);
            for (int r=top+1; r<=bottom; r++) ans.push_back(matrix[r][right]);
            if (top < bottom) for (int c=right-1; c>=left; c--) ans.push_back(matrix[bottom][c]);
            if (left < right) for (int r=bottom-1; r>=top+1; r--) ans.push_back(matrix[r][left]);
            cout << "end" << endl;
            top++;
            bottom--;
            left++;
            right--;
        }
        
        return ans;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //return spiralOrder_map(matrix);
        return spiralOrder_layers(matrix);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto expect1 = vector<int> {1,2,3,6,9,8,7,4,5};
    assert(Solution().spiralOrder(input1) == (expect1));
    
    auto input2 = vector<vector<int>> {{1, 2, 3, 4}, {5, 6, 7, 8}, {9,10,11,12}};
    auto expect2 = vector<int> {1,2,3,4,8,12,11,10,9,5,6,7};
    assert(Solution().spiralOrder(input2) == (expect2));
    return 0;
}