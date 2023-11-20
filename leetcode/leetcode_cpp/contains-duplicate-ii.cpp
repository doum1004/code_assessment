/*
https://leetcode.com/problems/contains-duplicate-ii

Solutions. Hash map
time: o(n)
space: o(n)

*/
class Solution {a
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i=0; i<nums.size(); ++i) {
            if (m.count(nums[i])) {
                if (abs(m[nums[i]] - i) <= k) return true;    
            }
            m[nums[i]] = i;
        }
        return false;
    }
};