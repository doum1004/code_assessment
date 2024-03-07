/*
https://leetcode.com/problems/increasing-triplet-subsequence

Solution1. Max List
time: o(n)
space: o(n)

Solution2. One pass
time: o(n)
space: o(1)
*/
class Solution {
public:
    bool increasingTriplet_1(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxRight(n, 0);
        maxRight[n-1] = nums[n-1];
        for (int i=n-2; i>=0; --i) {
            maxRight[i] = max(nums[i], maxRight[i+1]);
        }

        int minLeft = nums[0];
        for (int i=1; i<n-1; ++i) {
            if (minLeft < nums[i] && nums[i] < maxRight[i+1])
                return true;
            minLeft = min(minLeft, nums[i]);
        }
        return false;
    }
    bool increasingTriplet_2(vector<int>& nums) {
        int low = INT_MAX;
        int middle = INT_MAX;
        for (int i=0; i<nums.size(); ++i) {
            if (middle < nums[i]) return true;
            if (nums[i] < low) low = nums[i];
            else if (nums[i] > low && nums[i] < middle) middle = nums[i];
        }
        return false;
    }
    bool increasingTriplet(vector<int>& nums) {
        return increasingTriplet_2(nums);
    }
};