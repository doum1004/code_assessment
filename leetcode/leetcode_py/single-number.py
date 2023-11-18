'''
https://leetcode.com/problems/single-number

Solution1. Iterate. Map count
time: o(n)
space: o(n)

Solution2. sort
time: o(nlogn)
space: o(1)

Solution3. bitwise xor operator
time: o(n)
space: o(1)

0 0 | 0
0 1 | 1
1 0 | 1
1 1 | 0

A^A^B = B^A^A = B
'''

class Solution:
    def singleNumber_1(self, nums: List[int]) -> int:
        m = {}
        for n in nums:
            if not n in m:
                m[n] = 1
            else:
                m[n] += 1

        for k in m:
            if m[k] == 1:
                return k
        return 1
        
    def singleNumber_2(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                if i == 1:
                    return nums[0]
                if (i == len(nums) - 1 or nums[i] != nums[i+1]):
                    return nums[i]
        return nums[0]

    def singleNumber_3(self, nums: List[int]) -> int:
        ans = 0
        for n in nums:
            ans ^= n
        return ans

    def singleNumber(self, nums: List[int]) -> int:
        return self.singleNumber_3(nums)
        