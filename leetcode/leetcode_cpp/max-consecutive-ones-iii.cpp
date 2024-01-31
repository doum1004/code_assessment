/*
https://leetcode.com/problems/max-consecutive-ones-iii

1. Sliding window
time: o(n)
space: o(1)
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        for (int r=0, l=0; r<nums.size(); ++r) {
            if (nums[r] == 0) k -= 1;
            while (k < 0 && l < r) {
                if (nums[l] == 0) k += 1;
                l += 1;
            }
            if (k >= 0)
                res = max(res, r-l+1);
        }
        return res;
    }
};