/*
https://leetcode.com/problems/minimum-size-subarray-sum

Solutions1. slinding window
time: o(n)
space: o(1)

Solutions2. binary search
time: o(nlogn)
space: o(1)

2 3 1 2 4 3 (7)

0 2 5 6 8 12 15

1 4 4 (4)

9 1 2 3 4 5 (10)

0 10 11 13 16 20 25

*/

class Solution {
public:
    int minSubArrayLen_1(int target, vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;        
        int res = INT_MAX;
        int l = 0;
        int r = 0;
        int sum = 0;
        while (r<n) {
            sum += nums[r];
            while (sum >= target) {
                res = min(res, r - l + 1);
                sum -= nums[l++];
            }
            r++;
        }
        return res == INT_MAX ? 0 : res;
    }
    
    int minSubArrayLen_2(int target, vector<int>& nums) {
        int n = nums.size(), len = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = n; i >= 0 && sums[i] >= target; i--) {
            // i == r_idx
            if (sums[i] < target)
                break;
            int l_idx = upper_bound(sums.begin(), sums.end(), sums[i] - target) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        return minSubArrayLen_2(target, nums);
    }
};