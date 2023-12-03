#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/rotate-image

Solution 1. Rotate four trectangles
time: o(n^2)
space: o(1)
// 1 2 3        7 4 1
// 4 5 6        8 5 2
// 7 8 9        9 6 3

Solution 2. clockwise rotate. first reverse up to down, then swap the symmetry 
time: o(n^2)
space: o(1)
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
 * 
// 1. swap symmetry
// 2. reverse
(or 2->1)

 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
 * 
// 1. reverse (for (auto &it : matrix) reverse(it.begin(), it.end()))
// 2. swap symmetry. same

*/

class Solution {
public:
    void rotate_1(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int n1 = n / 2;
        for (int i=0; i<n; ++i) {
            int n2 = n - 2 * i - 1;
            for (int j=i; j<n2+i; ++j) {
                int p1_x = i, p1_y = j;
                int p2_x = j, p2_y = n-i-1;
                int p3_x = n-i-1, p3_y = n-j-1;
                int p4_x = n-j-1, p4_y = i;
                auto t = matrix[p1_x][p1_y];
                matrix[p1_x][p1_y] = matrix[p4_x][p4_y];
                matrix[p4_x][p4_y] = matrix[p3_x][p3_y];
                matrix[p3_x][p3_y] = matrix[p2_x][p2_y];
                matrix[p2_x][p2_y] = t;
            }
        }
    }
    void rotate_2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (int i=0; i<n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        return rotate_2(matrix);
    }
};

int main()
{
    auto input1 = vector<vector<int>>();
    input1.push_back(vector<int> {1, 2, 3});
    input1.push_back(vector<int> {4, 5, 6});
    input1.push_back(vector<int> {7, 8, 9});
    auto expect1 = vector<vector<int>>();
    expect1.push_back(vector<int> {7, 4, 1});
    expect1.push_back(vector<int> {8, 5, 2});
    expect1.push_back(vector<int> {9, 6, 3});
    Solution().rotate(input1);
    assert(input1
        == expect1);
    return 0;
}
