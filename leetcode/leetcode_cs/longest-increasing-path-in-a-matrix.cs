//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

public class Solution {
    int[] offset = {0,1,0,-1,0};
    private int dfs(ref int[][] matrix, int[,] cache, int row, int col) {
        if (cache[row,col] != 0) return cache[row,col];
        int n = matrix.Length, m = matrix[0].Length;
        
        for (int i=0; i<=3; ++i) {
            int n_r = row + offset[i], n_c = col + offset[i+1];
            if (n_r < 0 || n_c < 0 || n_r >= n || n_c >= m || matrix[row][col] >= matrix[n_r][n_c]) continue;
            
            cache[row,col] = Math.Max(cache[row,col], dfs(ref matrix, cache, n_r, n_c));
        }
        
        cache[row,col]++;
        return cache[row,col];
    }
    
    public int LongestIncreasingPath(int[][] matrix) {
        if (matrix.Length < 1 || matrix[0].Length < 1) return 0;
        int n = matrix.Length, m = matrix[0].Length;
        
        int res = 0;
        var cache = new int[n,m];
        for (int r=0; r<n; ++r) {
            for (int c=0; c<m; ++c) {
                res = Math.Max(res, dfs(ref matrix, cache, r, c));
            }
        }
        return res;
    }
}