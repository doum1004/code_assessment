'''
https://leetcode.com/problems/find-the-difference-of-two-arrays

1. Set
time: o(n)
space: o(n)
'''
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        s1 = set()
        for num in nums1:
            s1.add(num)
        s2 = set()
        for num in nums2:
            s2.add(num)

        res1 = []
        for num in s1:
            if num not in s2:
                res1.append(num)
            
        res2 = []
        for num in s2:
            if num not in s1:
                res2.append(num)
        return [res1, res2]