/*
https://leetcode.com/problems/rotate-array

Soltuion1. Brute force
time: o(n*k)
space: o(1)

Solution2. Vector
time: o(n)
space: o(n)

Solution3. Reverse. Math
time: o(n)
space: o(1)

*/

class Solution {
public:
    void rotate_1(vector<int>& nums, int k) {
        if (nums.size() < 2) return;
        int t = 0, t1 = 0;
        k = k % nums.size();
        for (int i=0; i<k; ++i) {
            t = nums[0];
            for (int j=0; j<nums.size(); ++j) {
                int n = j + 1;
                if (n >= nums.size()) n -= nums.size();
                int t1 = nums[n];
                nums[n] = t;
                t = t1;
            }
        }
    }
    void rotate_2(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        for (int i=0; i<nums.size(); ++i) {
            int n = i + k;
            if (n >= nums.size()) n -= nums.size();
            ans[n] = nums[i];
        }
        for (int i=0; i<nums.size(); ++i) {
            nums[i] = ans[i];
        }
    }

    void rotate_3(vector<int>& nums, int k) {
        if (nums.size() < 2) return;
        k = k % nums.size();
        
        auto reverse = [](vector<int>& nums, int l, int r) {
            while (l < r) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l += 1;
                r -= 1;
            }
        };

        reverse(nums, 0, nums.size() - k - 1);
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }

    void rotate(vector<int>& nums, int k) {
        return rotate_3(nums, k);
    }
};