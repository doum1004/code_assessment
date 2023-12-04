/*
https://leetcode.com/problems/set-matrix-zeroes

Solution1. Hashmap. Mark all '0'
time: o(n^3) m*n + m*n*(m+n)
space: o(mn)

Solution2. Hashmap. Mark only one per row or col 
time: o(mn)
space: o(m+n)

Solution3. Flag first row and col and mark from second row and col
time: o(mn)
space: o(1)
*/

class Solution {
public:
    void setZeroes_1(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        if (m == 0) return;

        vector<pair<int,int>> l;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (matrix[i][j] == 0)
                    l.push_back({i,j});
            }
        }

        for (auto values : l) {
            auto row = values.first;
            auto col = values.second;
            for (int i=0; i<m; ++i)
                matrix[row][i] = 0;
            for (int i=0; i<n; ++i)
                matrix[i][col] = 0;
        }
    }

    void setZeroes_2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        if (m == 0) return;

        //space:m+n
        unordered_set<int> rowMarks; // n
        unordered_set<int> colMarks; // m

        //time: m*n
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (matrix[i][j] == 0) {
                    rowMarks.insert(i);
                    colMarks.insert(j);
                }
            }
        }

        //time: m*n
        for (auto r : rowMarks) {
            for (int c=0; c<m; ++c) {
                matrix[r][c] = 0;
            }
        }

        //time: m*n
        for (auto c : colMarks) {
            for (int r=0; r<n; ++r) {
                matrix[r][c] = 0;
            }
        }
    }

    void setZeroes_3(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        if (m == 0) return;

        bool flagRow = false, flagCol = false;
        for (int i=0; i<n; ++i) {
            if (matrix[i][0] == 0) {
                flagRow = true;
                break;
            }
        }
        for (int i=0; i<m; ++i) {
            if (matrix[0][i] == 0) {
                flagCol = true;
                break;
            }
        }

        // mark on first row and col
        for (int i=1; i<n; ++i) {
            for (int j=1; j<m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // visit and fill 0 if there is mark on there first row or col
        for (int i=1; i<n; ++i) {
            for (int j=1; j<m; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (flagRow) {
            for (int i=0; i<n; ++i)
                matrix[i][0] = 0;            
        }

        if (flagCol) {
            for (int i=0; i<m; ++i)
                matrix[0][i] = 0;            
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        setZeroes_3(matrix);        
    }
};
