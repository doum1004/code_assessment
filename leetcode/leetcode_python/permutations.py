from typing import List

"""
https://leetcode.com/problems/permutations/submissions/

"""

class Solution:
    def permute_nextpermutation(self, nums: List[int]) -> List[List[int]]:
        n_nums = len(nums)
                
        res = []
        if not n_nums:
            return res
        
        n = 1
        for i in range(1,n_nums+1):
            n *= i
        
        for i in range(n):
            l = n_nums-2
            # find l
            while (l >= 0):
                if (nums[l] < nums[l+1]):
                    break
                l -= 1

            if l < 0:
                nums = nums[::-1]
            else:
                # find r
                r = l+1
                while (r < n_nums):
                    if nums[l] > nums[r]:
                        break
                    r += 1
                r -= 1

                # swap l,r
                nums[l], nums[r] = nums[r], nums[l]
                nums[l+1:] = nums[l+1:][::-1]
            res.append(list(nums))
            
        return res
        
    def permute_backtracking(self, nums: List[int]) -> List[List[int]]:
        res = []
        def permute_recursion(nums, i):
            nums = nums[:]
            if len(nums) == i:
                res.append(nums)
            else:
                for j in range(i, len(nums)):
                    nums[i], nums[j] = nums[j], nums[i]
                    permute_recursion(nums, i+1)
                    
        permute_recursion(nums, 0)
        return res
        
        
    def permute(self, nums: List[int]) -> List[List[int]]:
        #return self.permute_nextpermutation(nums)
        return self.permute_backtracking(nums)
        
        
        