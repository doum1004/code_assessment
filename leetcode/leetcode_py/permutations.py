from typing import List

"""
https://leetcode.com/problems/permutations

soltuion1. permute_nextpermute. two pointers (swap, reverse)
// time; o(n*n!). n(len(nums))*n!(all number of permutation)
// space: o(1). answer(n!)

1. itearte in factorial (n)
2. find l idx from last (nums[l] < nums[l+1])
2.1 if l is none. break iteration
2.2 else find r idx from l (nums[r] > nums[l], most right most)
2.2.1 swap l,r. and reverse(l+1,r). add nums into answer

solution2. backtracking(change, recursion, undo)
// time: o(n*n!)
// space: o(n!) recursion

In recursion(nums, i, ans)
if i == nums.size. add in ans
else iterate j (i to end). swap(i,j) and call recursion(num, i+1)

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
        
        
    def permute_backtracking2(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def recursive(i):
            n = len(nums)
            if n == i:
                ans.append(nums[:])
                return
            for j in range(i,n):
                nums[i], nums[j] = nums[j], nums[i]
                recursive(i+1)
                nums[i], nums[j] = nums[j], nums[i]
                
        recursive(0)
        return ans
            
    def permute(self, nums: List[int]) -> List[List[int]]:
        #return self.permute_nextpermutation(nums)
        return self.permute_backtracking(nums)
        
        
        