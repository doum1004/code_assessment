/*
Solution1. find range and binary search
time: o(logn) m + logn
space: o(1)
*/

class Solution {
public:
    bool bs(vector<int>& rowData, int l, int r, int target) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (rowData[m] == target)
                return true;
            if (rowData[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return false;
    }

    bool searchMatrix_1(vector<vector<int>>& matrix, int target) {
        int n1 = matrix.size();
        if (!n1) return false;
        int n2 = matrix[0].size();
        if (!n2) return false;

        for (int i=0; i<n1; ++i) {
            for (int j=0; j<n2; ++j) {
                if (target < matrix[i][j]) return false;
                if (target > matrix[i][n2 - 1]) continue;

                if (bs(matrix[i], 0, n2 - 1, target))
                    return true;
            }
        }

        return false;
    }

    bool searchMatrix_test(vector<vector<int>>& matrix, int target) {
        int n1 = matrix.size();
        if (!n1) return false;
        int n2 = matrix[0].size();
        if (!n2) return false;

        int row = 0;
        int col = n2 - 1;

        while (row < n1 && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix_1(matrix, target);
    }
};