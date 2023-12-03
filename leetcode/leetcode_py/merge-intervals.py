'''
https://leetcode.com/problems/merge-intervals

Solution1. sort and merge
time: o(nlogn) sort
space: o(n) ans vector

 [1,3], [2,6], [8,10], [15,18]
 sort
 [1,3], [2,6], [8,10], [15,18]
 merge vector
 v [1, 3]
 v [1, 6]
 v [1, 6] [8, 10]
 v [1, 6] [8, 10] [15, 18]
'''
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1: return intervals
        intervals.sort()

        res = []
        for interval in intervals:
            if not res or res[-1][1] < interval[0]:
                res.append(interval)
            else:
                res[-1][1] = max(res[-1][1], interval[1])
        return res

        