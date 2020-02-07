#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

/**
https://leetcode.com/problems/search-a-2d-matrix-ii/

// 1. brute force
// time: o(r*c)
// space: o(1)

// 2. Binary search
// time: o(r*clogc)
// space: o(1)

// 3. search from bottom left to move up/right
// time: o(m+n)
// space: o(1)


*/

class Solution {
public:
    bool searchMatrix_bruteforce(vector<vector<int>>& matrix, int target) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return false;

        int n_r = matrix.size(), n_c = matrix[0].size();
        for (int r=0; r<n_r; ++r) {
            for (int c=0; c<n_c; ++c) {
                if (matrix[r][c] == target) return true;
            }
        }
        
        return false;
    }
    
    bool searchMatrix_bruteforce_binsearch(vector<vector<int>>& matrix, int target) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return false;

        int n_r = matrix.size(), n_c = matrix[0].size();
        for (int r=0; r<n_r; ++r) {
            if (binary_search(matrix[r].begin(), matrix[r].end(), target)) return true;
        }
        
        return false;
    }
    
    bool searchMatrix_search_bottom_left(vector<vector<int>>& matrix, int target) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return false;

        int n_r = matrix.size(), n_c = matrix[0].size();
        int r = n_r-1, c = 0;
        while (r >= 0 && c < n_c) {
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] < target) c++;
            else r--;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //return searchMatrix_bruteforce(matrix, target);
        //return searchMatrix_bruteforce_binsearch(matrix, target);
        return searchMatrix_search_bottom_left(matrix, target);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{1,   4,  7, 11, 15}, {2,   5,  8, 12, 19}, {3,   6,  9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    assert(Solution().searchMatrix(input1, 5)
        == true);
    assert(Solution().searchMatrix(input1, 20)
        == false);

    return 0;
}