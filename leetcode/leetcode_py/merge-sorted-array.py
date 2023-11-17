from typing import List

"""
https://leetcode.com/problems/merge-sorted-array/
"""

class Solution:
    def merge_2(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        # time o(n)
        # space o(1)
        i = m - 1
        j = n - 1
        k = m + n - 1
        while j >= 0:
            if i >= 0 and nums1[i] >= nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1

    def merge_1(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        # time o(nlogn)
        # space o(1)
        for j in range(n):
            nums1[m+j] = nums2[j]
        nums1.sort()        


    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        #self.merge_1(nums1, m, nums2, n)
        self.merge_2(nums1, m, nums2, n)
        