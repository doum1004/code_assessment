/*
https://leetcode.com/problems/single-number-ii

Solutions1. hashmap
time: o(n)
space: o(n)

Solutions2. sort and check
time: o(nlogn)
space: o(1)

Solutions3. Bitmanipluation
time: o(n) 32n
space: o(1)
*/
class Solution {
public:
    int singleNumber_1(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }
        for (auto values : m) {
            if (values.second == 1)
                return values.first;
        }
        return -1;
    }
    int singleNumber_2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i = i+3) {
            if (i + 2 >= nums.size()) return nums[i];
            if (nums[i] != nums[i+2]) return nums[i];
        }
        return -1;
    }
    int singleNumber_3(vector<int>& nums) {
        int ans = 0;
        for (int i=0; i<32; ++i) {
            int count = 0;
            int b = 1 << i;
            for (auto n:nums) if (n & b) count++;
            if (count % 3) ans |= b;
        }
        return ans;
    }
    int singleNumber(vector<int>& nums) {
        return singleNumber_3(nums);
    }
};