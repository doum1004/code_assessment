'''
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
'''
class Solution:
    def setZeroes_1(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        if not n: return
        m = len(matrix[0])
        if not m: return

        marks = []
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    marks.append((i, j))
        
        for i, j in marks:
            for col in range(m):
                matrix[i][col] = 0
            for row in range(n):
                matrix[row][j] = 0

    def setZeroes_2(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        if not n: return
        m = len(matrix[0])
        if not m: return

        rows, cols = set(), set()
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)
        
        for row in rows:
            for col in range(m):
                matrix[row][col] = 0

        for col in cols:
            for row in range(n):
                matrix[row][col] = 0

            
    def setZeroes_3(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        if not n: return
        m = len(matrix[0])
        if not m: return

        rowFlag, colFlag = False, False
        for row in range(n):
            if matrix[row][0] == 0:
                rowFlag = True
                break
        for col in range(m):
            if matrix[0][col] == 0:
                colFlag = True
                break
        for row in range(1,n):
            for col in range(1,m):
                if matrix[row][col] == 0:
                    matrix[row][0] = 0
                    matrix[0][col] = 0
        for row in range(1,n):
            for col in range(1,m):
                if matrix[0][col] == 0 or matrix[row][0] == 0:
                    matrix[row][col] = 0
        if rowFlag:
            for row in range(n):
                matrix[row][0] = 0
        if colFlag:
            for col in range(m):
                matrix[0][col] = 0
                


    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        return self.setZeroes_3(matrix)
        