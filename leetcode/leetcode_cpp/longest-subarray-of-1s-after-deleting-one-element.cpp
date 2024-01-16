/*
https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

Solution1. sliding window
time: o(n)
space: o(1)

Solution2. iterate cur and prev sections
time: o(n)
space: o(1)
*/

class Solution {
public:
    int longestSubarray_1(vector<int>& nums) {
        int r = 0, m = -1;
        int res = 0;
        int curSum = 0;
        while (r < nums.size()) {
            if (nums[r]) {
                curSum += 1;
            }
            else {
                if (m == -1) {
                    m = r;
                }
                else {
                    res = max(res, curSum);
                    curSum = 0;
                    r = m;
                    m = -1;
                }
            }
            r += 1;
        }
        
        res = max(res, curSum);
        return nums.size() == res ? res - 1 : res;
    }

    int longestSubarray_2(vector<int>& nums) {
        int cur = 0, prev = 0;
        int res = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]) {
                cur += 1;
            }
            else {
                res = max(res, cur + prev);
                prev = cur;
                cur = 0;
            }
        }
        res = max(res, cur + prev);
        return res == nums.size() ? res - 1 : res;
    }

    int longestSubarray(vector<int>& nums) {
        return longestSubarray_2(nums);
    }
};