from typing import List

"""
https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
"""

class Solution:
    def minDominoRotations_greedy(self, A: List[int], B: List[int]) -> int:
        def minDominoRotations(num):
            rotation_a, rotation_b = 0, 0
            for i in range(len(A)):
                if A[i] != num and B[i] != num:
                    return -1
                
                if A[i] != num:
                    rotation_a += 1
                
                if B[i] != num:
                    rotation_b += 1
            return min(rotation_a, rotation_b)
        
        num1, num2 = A[0], B[0]
        result1 = minDominoRotations(num1)
        result2 = result1
        if num1 != num2:
            result2 = minDominoRotations(num2)
        
        if result1 == -1 or result2 == -1:
            return max(result1, result2)
        return min(result1, result2)
        
        
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        return self.minDominoRotations_greedy(A, B)
        
        