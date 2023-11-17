from typing import List

"""
1. sort
2. set
3. bit
4. math

"""

class Solution:
    def missingNumber_sort(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums)):
            if i != nums[i]:
                return i
            
        return len(nums)
    
    def missingNumber_map(self, nums: List[int]) -> int:
        s = [0] * (len(nums) + 1)
        for n in nums:
            s[n] = 1
        
        for i in range(len(s)):
            if s[i] == 0:
                return i
            
        return -1
    
    def missingNumber_bit(self, nums: List[int]) -> int:
        b = len(nums)
        for i in range(len(nums)):
            b ^= i ^ nums[i]
        return b
    
    def missingNumber_math(self, nums: List[int]) -> int:
        sum1 = int(len(nums) * (len(nums) + 1) / 2)
        sum2 = 0
        for n in nums:
            sum2 += n
            
        return sum1 - sum2
        
    def missingNumber(self, nums: List[int]) -> int:
        #return self.missingNumber_sort(nums)
        #return self.missingNumber_map(nums)
        return self.missingNumber_bit(nums)
        #return self.missingNumber_math(nums)