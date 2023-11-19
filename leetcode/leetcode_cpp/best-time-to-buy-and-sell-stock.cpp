/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock

Solution1. Find min value before index and find max value from it

   3 2 1 5 7
l: 3. max value: 0
l: 2. max value: 0
l: 1. max value: 0
l: 1. max value: 4
l: 1. max value: 6

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = INT_MAX;
        int res = 0;
        for (int i=0; i<prices.size(); ++i) {
            l = min(l, prices[i]);
            res = max(res, prices[i] - l);
        }
        return res;
    }
};