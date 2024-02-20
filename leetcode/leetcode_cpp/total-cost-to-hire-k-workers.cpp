/*
https://leetcode.com/problems/total-cost-to-hire-k-workers

1. min heap
time: nlogn
space: o(n)
*/
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> q1, q2;
        int l = 0, r = costs.size()-1;
        long long res = 0;
        while (k > 0) {
            while (q1.size() < candidates && l<=r) q1.push(costs[l++]);
            while (q2.size() < candidates && l<=r) q2.push(costs[r--]);
            auto a = q1.size() ? q1.top() : INT_MAX;
            auto b = q2.size() ? q2.top() : INT_MAX;
            if (a <= b) {
                res += a;
                q1.pop();
            }
            else {
                res += b;
                q2.pop();
            }
            k -= 1;
        }
        return res;
    }
};