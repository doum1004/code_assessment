/*
https://leetcode.com/problems/maximum-average-subarray-i

Solution1. Sliding Window
time: o(n)
space: o(1)
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = 0;
        double sum = 0;
        while (r < k) sum += nums[r++];
        double res = sum;

        while (r < nums.size()) {
            sum += nums[r] - nums[l];
            res = max(res, sum);
            r += 1;
            l += 1;
        }
        return res / k;
    }
};