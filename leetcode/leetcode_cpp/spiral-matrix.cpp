#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/spiral-matrix/

// Solution1. visit node with visited board
// time: o(n)
// space: o(n). visited(n). queue(1)

// Solution2. layer by layer
Loop for each layers(top layer, right layer, bottom layer, left layer) till end
// time: o(n)
// space: o(1)

*/

class Solution {
public:
    vector<int> spiralOrder_space(vector<vector<int>>& matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return vector<int>();
        
        int n1 = matrix.size();
        int n2 = matrix[0].size();
        
        vector<vector<bool>> v(n1, vector<bool>(n2, false));
            
        int dir = 1; //1(right), 2(down), 3(left), 4(up)
        
        queue<pair<int,int>> q;
        q.push({0,0});
            
        vector<int> ans;
        while (!q.empty()) {
            auto r = q.front().first;
            auto c = q.front().second;
            q.pop();
            v[r][c] = true;
            ans.push_back(matrix[r][c]);
            
            int count=0;
            while (++count < 5) {
                int temp_r = r;
                int temp_c = c;
                
                if (dir == 1) {
                    temp_c++;
                }
                else if (dir == 2) {
                    temp_r++;
                }
                else if (dir == 3) {
                    temp_c--;
                }
                else if (dir == 4) {
                    temp_r--;
                }
                
                if (temp_r < 0 || temp_c < 0 || temp_r >= n1 || temp_c >= n2 || v[temp_r][temp_c] != false) {
                    dir++;
                    if (dir == 5) dir = 1;
                }
                else {
                    q.push({temp_r, temp_c});
                    break;
                }
            }
        }
        
        return ans;
    }
    
    vector<int> spiralOrder_nospace(vector<vector<int>>& matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return vector<int>();
        
        int n1 = matrix.size();
        int n2 = matrix[0].size();
        
        int top=0, left=0, right=n2-1, bottom=n1-1;
        vector<int> ans;
        while (top<=bottom && left<=right) {
            // top to right
            //if (top<=bottom)
            {
                for (int c=left; c<=right; ++c) {
                    ans.push_back(matrix[top][c]);
                }
                top++;
            }
            //if (left<=right)
            {
                for (int r=top; r<=bottom; ++r) {
                    ans.push_back(matrix[r][right]);
                }
                right--;
            }

            if (!(top<=bottom && left<=right)) break;

            //if (top<=bottom)
            {
                for (int c=right; c>=left; --c) {
                    ans.push_back(matrix[bottom][c]);
                }
                bottom--;
            }
            if (left<=right) {
                for (int r=bottom; r>=top; --r) {
                    ans.push_back(matrix[r][left]);
                }
                left++;
            }
        }
        return ans;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //return spiralOrder_space(matrix);
        return spiralOrder_nospace(matrix);
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