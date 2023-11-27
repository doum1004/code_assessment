'''
Solution1. find range and binary search
time: o(logn) m + logn
space: o(1)
'''
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n1 = len(matrix)
        if not n1: return False
        n2 = len(matrix[0])
        if not n2: return False

        # find right row
        row = 0
        for row in range(n1):
            if matrix[row][0] <= target and matrix[row][n2-1] >= target:
                break
            elif row == n1 - 1:
                return False
        
        def bs(l, r):
            while l <= r:
                m = l + (r - l) // 2
                if matrix[row][m] == target:
                    return True
                if matrix[row][m] > target:
                    r = m - 1
                else:
                    l = m + 1
            
            return False
                    
        return bs(0, n2-1)

        
        