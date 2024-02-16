'''
https://leetcode.com/problems/total-cost-to-hire-k-workers

1. min heap
time: nlogn
space: o(n)
'''
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        q1, q2 = [], []
        l, r = 0, len(costs) - 1
        res = 0
        while k > 0:
            while len(q1) < candidates and l <= r:
                heappush(q1, costs[l])                
                l += 1
            while len(q2) < candidates and l <= r:
                heappush(q2, costs[r])                
                r -= 1
            a = q1[0] if q1 else float(inf)
            b = q2[0] if q2 else float(inf)
            if a <= b:
                res += a
                heappop(q1)
            else:
                res += b
                heappop(q2)
            k -= 1
        return res
        