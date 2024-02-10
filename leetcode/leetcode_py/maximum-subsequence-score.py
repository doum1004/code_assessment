'''
https://leetcode.com/problems/maximum-subsequence-score

1. Sort + Heap
time: o(nlogn)
space: o(n)
'''
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        v = []
        for i in range(len(nums1)):
            v.append((nums2[i], nums1[i]))
        v.sort(reverse = True)
        
        res, s = 0, 0
        h = []
        for values in v:
            if len(h) == k:
                s -= heapq.heappop(h)
            heapq.heappush(h, values[1])
            s += values[1]
            if len(h) >= k:
                res = max(res, s * values[0])
            
        return res
        