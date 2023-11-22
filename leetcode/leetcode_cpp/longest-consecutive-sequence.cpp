/*
https://leetcode.com/problems/longest-consecutive-sequence

Solutions1. sort + sliding window
time: o(nlogn)
space: o(1)

Solutions2. store it into hash map and iterate to find it has next or not
time: o(n)
space: o(1)

*/

class Solution {
public:
    int longestConsecutive_1(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        sort(nums.begin(), nums.end());
        int r = 1;
        int cnt = 1;
        int res = 1;
        while (r < nums.size()) {
            if (nums[r - 1] + 1 == nums[r]) {
                cnt++;
                res = max(res, cnt);
            }
            else if (nums[r - 1] != nums[r]) {
                cnt = 1;
            }
            r++;
        }
        return res;
    }

    int longestConsecutive_2(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        
        unordered_set<int> h;
        for (auto n : nums)
            h.insert(n);

        int res = 0;
        for (auto n : h) {
            if (h.count(n-1))
                continue;
            int cnt = 1;
            while (h.count(n + cnt)) {
                cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }

    int longestConsecutive(vector<int>& nums) {
        return longestConsecutive_2(nums);
    }
};