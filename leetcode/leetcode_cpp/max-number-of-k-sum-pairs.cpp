/*
https://leetcode.com/problems/max-number-of-k-sum-pairs

Solution1. Sort and two pointers
time: o(nlogn) nlogn + n
space: o(1)

Solution2. Map
time: o(n)
space: o(n)
*/
class Solution {
public:
    int maxOperations_1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int res = 0;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == k) {
                res += 1;
                l++;
                r--;
            }
            else if (sum < k) l++;
            else r--;
        }
        return res;
    }
    int maxOperations_2(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int res = 0;
        for (int i=0; i<nums.size(); ++i) {
            int target = k - nums[i];
            if (m[target]) {
                res += 1;
                m[target] -= 1;
            }
            else {
                m[nums[i]] += 1;
            }
        }
        return res;
    }
    int maxOperations(vector<int>& nums, int k) {
        return maxOperations_2(nums, k);
    }
};