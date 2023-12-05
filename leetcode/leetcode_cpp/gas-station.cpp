/*
https://leetcode.com/problems/gas-station

Solution. One pass. Tracking total and cur sum gas.
time: o(n)
space: o(1)

1. Iterate gas(cost)
  1.1.Total Sum , Cur Sum.
  1.2 If cur sum is below than 0: Reset cursum and ans(i+1)
3. check total sum < 0: return -1 else return ans
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = 0, totalSum = 0, curGas = 0;
        for (int i=0; i<n; ++i) {
            totalSum += gas[i] - cost[i];
            curGas += gas[i] - cost[i];
            if (curGas < 0) {
                ans = i+1;
                curGas = 0;
                }
        }
        return (totalSum < 0) ? -1 : ans;
    }
};