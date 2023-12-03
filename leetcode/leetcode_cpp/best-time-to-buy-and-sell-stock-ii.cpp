/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

Solution1. Two Pointers
time: o(n)
space: o(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int res = 0;
        int l = 0;
        int r = 1;
        while (r < n) {
            if (prices[l] < prices[r])
                res += prices[r] - prices[l];
            l++;
            r++;
        }
        
        return res;
    }
};