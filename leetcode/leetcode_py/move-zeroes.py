'''
https://leetcode.com/problems/move-zeroes

Soluiton1 iterate vector and erase and pushback
time: o(n^2) n(iterate) * n(erase)
space: o(1)

for (int i=0; i<nums.size(); ++i) {
    if (nums[i] == 0) {
        nums.erase(nums.begin() + i);
        nums.push_back(nums[i]);
        i--;
    }
}

Soluiton2 iterate swap none zero nums on left
time: o(n)
space: o(1)

auto l=0;
for (auto &n:nums) { if (n !=0) swap(n, nums[l++])}
'''
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n <= 1: return
        l = 0
        for i in range(n):
            if nums[i] != 0:
                nums[l], nums[i] = nums[i], nums[l]
                l += 1