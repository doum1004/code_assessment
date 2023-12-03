'''
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
'''
class Solution:
    def rotate_1(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        n1 = n//2
        for i in range(n1):
            n2 = n - 2 * i - 1
            for j in range(i, n2+i):
                p1_x, p1_y = i, j
                p2_x, p2_y = j, n-i-1
                p3_x, p3_y = n-i-1, n-j-1
                p4_x, p4_y = n-j-1, i
                t = matrix[p1_x][p1_y]
                matrix[p1_x][p1_y] = matrix[p4_x][p4_y]
                matrix[p4_x][p4_y] = matrix[p3_x][p3_y]
                matrix[p3_x][p3_y] = matrix[p2_x][p2_y]
                matrix[p2_x][p2_y] = t
                
    def rotate_2(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        for i in range(n):
            matrix[i].reverse()
 
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        self.rotate_2(matrix)
        