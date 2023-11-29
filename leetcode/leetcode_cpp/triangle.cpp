/*
https://leetcode.com/problems/triangle

Solution1. top down dp (memorization)
time: o(n^2)
space: o(n^2)

Solution2. bottom up dp tabulation (space opt)
time: o(n^2)
space: o(n)

1. Suppose that only the last level is given. 

4 1 8 3

Then what should be your answer?

If you thought 1, then congratulations 🎉 you are correct. This is our first subproblem. 

2. Now, the last two levels are given.

 6 5 7
4 1 8 3

Here, what should be the answer and what information do you need to store?

Clearly, the answer is 6 (5 -> 1). But, this may not be the optimal path. So, we need to store all the optimal paths, i.e.,
[(6 -> 1), (5 -> 1), 7 -> 3)] or [7, 6, 10]. This is our second subproblem.

3. Last 3 levels are given.

  3 4
 6 5 7
4 1 8 3

Again, what should be the answer and what information do you need to store (or use)?

Answer is 9 (3 -> 5 -> 1). Do we need to look again at all the paths? Can we use the information that we previously stored?
No and Yes.
If we replace the triangle as
  3 4
 7 6 10
then also, we'll get the same answer. And we can store this information as [(3 -> 6), (4 -> 6)] or [9, 10].

4. All levels are given

   2
  3 4
 6 5 7
4 1 8 3

Which can be replaced as:
   2
  9 10

And hence, our answer is 11 (2 -> 9)

Notice that we only require the information about the next row. So, instead of creating a 2D matrix, a 1D array is sufficient.

*/
class Solution {
public:
    unordered_map<int, unordered_map<int,int>> cc;
    int minimumTotal_1(vector<vector<int>>& triangle, int row, int col) {
        if (row < 0 || col < 0 || row >= triangle.size() || col >= triangle[row].size()) return INT_MAX;
        if (cc.count(row) && cc[row].count(col)) return cc[row][col];

        auto v = triangle[row][col];
        auto v1 = minimumTotal_1(triangle, row + 1, col);
        auto v2 = minimumTotal_1(triangle, row + 1, col + 1);
        if (v1 == INT_MAX && v2 == INT_MAX) v1 = 0;
        cc[row][col] = v + min(v1, v2);
        return cc[row][col];
    }

    int minimumTotal_1(vector<vector<int>>& triangle) { 
        int n1 = triangle.size();
        int n2 = triangle[0].size();
        if (!n1 || !n2) return 0;

        int res = minimumTotal_1(triangle, 0, 0);
        return res;
    }

    int minimumTotal_2(vector<vector<int>>& triangle) { 
        int n = triangle.size();
        for (int i=n-2; i>=0; --i) {
            for (int j=0; j<i+1; ++j) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return minimumTotal_2(triangle);
    }
};