/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

Solution1. Erase if duplicates
time: o(n^2). iterate * erase
space: o(1)

Solution2. Hashmap
time: o(n)
space: o(n)

Solution3. Without extra memory
time: o(n)
space: o(1)
*/
class Solution {
public:
    int removeDuplicates_1(vector<int>& nums) {        
        if (nums.size() < 2) return nums.size();
        int curNum = nums[0];
        int count = 1;
        for (int i=1; i<nums.size(); ++i) {
            if (curNum == nums[i]) {
                count++;
                if (count > 2)
                    nums.erase(nums.begin() + i--);
            } else {
                curNum = nums[i];
                count = 1;
            }
        }
        return nums.size();
    }

    int removeDuplicates_2(vector<int>& nums) {
        unordered_map<int, int> m;
        int cur = 0;
        for (int i=0; i<nums.size(); ++i) {
            m[nums[i]]++;
            if (m[nums[i]] < 3)
                nums[cur++] = nums[i];
        }
        return cur;
    }

    int removeDuplicates_3(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int k = 0;
        for (int i=2; i<nums.size(); ++i) {
            if (nums[i] != nums[k]) {
                nums[k+2] = nums[i];
                k++;
            }
        }
        return k+2;
    }
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicates_3(nums);
    }
};