'''
https://leetcode.com/problems/insert-interval

Solution. Add and iterate to merge
time: o(n)
space: o(n)
'''
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        if n == 0: return [newInterval]

        for i, interval in enumerate(intervals):
            if interval[0] > newInterval[0]:
                intervals.insert(i, newInterval)
                break
        if n == len(intervals):
            intervals.append(newInterval)

        res = []
        for interval in intervals:
            if not res or res[-1][1] < interval[0]:
                res.append(interval)
            else:
                res[-1][1] = max(res[-1][1], interval[1])
        return res
            
