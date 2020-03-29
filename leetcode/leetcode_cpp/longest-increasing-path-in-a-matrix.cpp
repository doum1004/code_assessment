#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/**
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

Solution1. DFS
time: o(2^n)
space: o(n) recursion

Solution2. DFS + DP
time: o(n)
space: o(n) recursion(n) + dp(n)

create dp table and store it whenever visited

Solution3. topological sort in BFS (todo)
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/discuss/193299/C%2B%2B-neat-topological-sort-no-DP!
time: o(n) build queue(n) BFS(n)
space: o(n) queue(n) + counter valid adjs(n)

1. build graph which has larger adjs and count it
2. BFS in queue. add adj in queue if counter is still valid

*/

class Solution {
public:
    int offset[5] = {0,1,0,-1,0};
    int dfs(vector<vector<int>>& m, vector<vector<int>>& cache, int r, int c) {
        if (cache[r][c] > 0) return cache[r][c];
        
        for (int i=0; i<=3; ++i) {
            int n_r = r + offset[i], n_c = c + offset[i+1];
            if (n_r < 0 || n_c < 0 || n_r >= m.size() || n_c >= m[0].size() || m[r][c] >= m[n_r][n_c]) continue;
            cache[r][c] = max(cache[r][c], dfs(m, cache, n_r, n_c));
        }
        
        return ++cache[r][c];
    }
    int longestIncreasingPath_dfs_memorization(vector<vector<int>>& matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return 0;
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> cache(n, vector<int>(m, 0));
        int res = 0;
        for (int r=0; r<n; ++r) {
            for (int c=0; c<m; ++c) {
                res = max(res, dfs(matrix, cache, r, c));
            }
        }
        return res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        return longestIncreasingPath_dfs_memorization(matrix);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{9,9,4},{6,6,8},{2,1,1}};
    assert(Solution().longestIncreasingPath(input1) == (4));

    auto input2 = vector<vector<int>> {{3,4,5},{3,2,6},{2,2,1}};
    assert(Solution().longestIncreasingPath(input2) == (4));
    
    return 0;
}