/*
https://leetcode.com/problems/find-pivot-index

1. Sum list and compare
time: o(n)
space: o(n)

2. Accumulate and distract in iteration
time: o(n)
space: o(1)
*/
class Solution {
public:
    int pivotIndex_1(vector<int>& nums) {
        if (!nums.size()) return -1;
        vector<int> nums_sum(nums.size(), 0);
        int s = 0;
        for (int i=nums.size()-1; i>=0; --i) {
            nums_sum[i] = s;
            s += nums[i];
        }
        // 0 1 8 11 17 22 28
        // 28 27 20 17 11 6 0
        
        s = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (s == nums_sum[i])
                return i;
            s += nums[i];
        }
        return -1;
    }
    int pivotIndex_2(vector<int>& nums) {
        if (!nums.size()) return -1;
        int s = 0;
        for (int& num : nums) s += num;

        int s2 = 0;
        for (int i=0; i<nums.size(); ++i) {
            s -= nums[i];
            if (s2 == s) return i;
            s2 += nums[i];
        }

        return -1;
    }
    int pivotIndex(vector<int>& nums) {
        return pivotIndex_2(nums);
    }
};