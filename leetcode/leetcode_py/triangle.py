'''
https://leetcode.com/problems/triangle

Solution1. top down dp (memorization)
time: o(n^2)
space: o(n^2)

Solution2. bottom up dp tabulation (space opt)
time: o(n^2)
space: o(n)
'''
class Solution:
    def minimumTotal_1(self, triangle: List[List[int]]) -> int:
        m = {}
        def recursive(row, col):
            if row == len(triangle):
                return 0
            if (row,col) in m: return m[(row,col)]
            v = triangle[row][col]
            v1 = recursive(row + 1, col)
            v2 = recursive(row + 1, col + 1)
            m[(row,col)] = v + min(v1,v2)
            return m[(row,col)]
        return recursive(0, 0)

    def minimumTotal_2(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        for i in range(n-2, -1, -1):  # for each row in triangle (skipping the last),
            for j in range(i+1):                  # loop through each element in the row
                triangle[i][j] += min(triangle[i+1][j],    # minimum sum from coordinate (x+1, y)
                                      triangle[i+1][j+1])  # minimum sum from coordinate (x+1, y+1)
        return triangle[0][0]
            
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        return self.minimumTotal_2(triangle)
        