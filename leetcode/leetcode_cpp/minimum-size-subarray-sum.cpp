/*
Solutions1. slinding window
time: o(n)
space: o(1)

Solutions2. binary search
time: o(nlogn)
space: o(1)

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
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - target) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        return minSubArrayLen_2(target, nums);
    }
};