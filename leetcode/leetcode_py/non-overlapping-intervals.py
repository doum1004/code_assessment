'''
https://leetcode.com/problems/non-overlapping-intervals
1. Sort and Iteration (greedy)
time: o(n)
space: o(1)
'''
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals or not len(intervals):
            return 0
        intervals.sort(key=lambda x: x[1])
        prev = intervals[0][1]
        res = 0
        for i in range(1, len(intervals)):
            if prev > intervals[i][0]:
                res += 1
            else:
                prev = intervals[i][1]
                
        return res
        