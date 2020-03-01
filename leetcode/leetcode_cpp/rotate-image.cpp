#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

// https://leetcode.com/problems/rotate-image/submissions/

// Solution 1. 
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
// 1. reverse
// 2. swap symmetry
/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
// 1. reverse (for (auto &it : matrix) reverse(it.begin(), it.end()))
// 2. swap symmetry. same

// Solution 2. Rotate four trectangles
// time: o(n^2)
// space: o(1)
// 1 2 3        7 4 1
// 4 5 6        8 5 2
// 7 8 9        9 6 3

// 0 < i < n/2+n%2
// 0 < j < n/2
// i = 0, j = 0, temp = 1, 3, 9, 7 rotate
// 7 2 1
// 4 5 6
// 9 8 3

// i = 1, j = 0, temp = 2, 6, 8, 4 rotate
// 7 4 1
// 8 5 2
// 9 6 3

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (true) {
            // solution1 reverse and swap symmetry
            reverse(matrix.begin(), matrix.end());
            int n = matrix.size();
            for (int i=0; i<n; ++i) {
                for (int j=i+1; j<n; ++j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        else {
            // solution2 rotate 4 rectangles
            auto n = matrix.size();
            for (int i=0; i<n/2+n%2; ++i) {
                for (int j=0; j<n/2; ++j) {
                    auto tmp = new int[4];
                    auto row = i;
                    auto col = j;

                    // store temp
                    for (int k=0; k<4; ++k) {
                        tmp[k] = matrix[row][col];
                        auto t = row;
                        row = col;
                        col = n - 1 - t;
                    }

                    // rotate by storing temp
                    for (int k=0; k<4; ++k) {
                        matrix[row][col] = tmp[(k+3) % 4];
                        auto t = row;
                        row = col;
                        col = n - 1 -t;
                    }
                }
            }
        }
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