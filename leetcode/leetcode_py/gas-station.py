'''
https://leetcode.com/problems/gas-station

Solution. One pass. Tracking total and cur sum gas.
time: o(n)
space: o(1)

1. Iterate gas(cost)
  1.1.Total Sum , Cur Sum.
  1.2 If cur sum is below than 0: Reset cursum and ans(i+1)
3. check total sum < 0: return -1 else return ans
'''
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        ans, total, cur = 0, 0, 0
        for i in range(len(gas)):
            total += gas[i] - cost[i]
            cur += gas[i] - cost[i]
            if cur < 0:
                cur = 0
                ans = i+1
        return ans if total >= 0 else -1
        
        