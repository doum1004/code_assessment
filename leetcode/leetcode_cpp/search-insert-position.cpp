/*
https://leetcode.com/problems/search-insert-position

Solution1. binary search and find target index
1 3 5 7 8 9 (1, 6)
return matched. or not find the cloest and return index or +1(if target is larger)

m = 0
while (l <= r)
    m = int((l+r)/2)
    if nums[m] == t: return m
    if (nums[m] >= t) r = m - 1;
    else l = m + 1
return nums[m] > t ? m : m + 1

l r m 
3 3 3

Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 2
Output: 1

Input: nums = [1,3,5,6], target = 7
Output: 4
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (!nums.size()) return -1;
        
        int l = 0, r = nums.size() - 1, m = 0;
        while (l<=r) {
            m = (l+r) / 2;
            if (nums[m] == target) return m;

            if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        return nums[m] > target ? m : m + 1;
    }
};