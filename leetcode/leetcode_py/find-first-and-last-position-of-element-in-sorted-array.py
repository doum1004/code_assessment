'''
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

Solution1. Iterate
time: o(n)
space: o(1)

Solution2. Binary search
time: o(logn)
space: o(1)

Solution3. lower bound / uppder bound (stl)
time: o(logn)
space: o(1)

Solution4. custom lower/upper bound
time: o(logn)
space: o(1)
'''
class Solution:
    def searchRange_1(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            if nums[i] == target:
                j = i
                while j + 1 < n and nums[j+1] == target:
                    j += 1
                return [i, j]
        return [-1, -1]

    def searchRange_2(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        l, r = 0, n-1
        while l<=r:
            m = (l+r) // 2
            if nums[m] == target:
                i = m
                j = m
                while i-1 >= 0 and nums[i-1] == target:
                    i -= 1
                while j+1 < n and nums[j+1] == target:
                    j += 1
                return [i, j]
            
            if nums[m] > target:
                r = m-1
            else:
                l = m+1
        return [-1, -1]

    def searchRange_4(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0: return [-1,-1]
        def lower_bound(t):
            i,j=0,len(nums)-1
            while i<j:
                m = (j-i)//2+i
                if nums[m] < t: i=m+1
                else: j=m
            return i if nums[i] == t else -1
            
        def upper_bound(t):
            i,j=0,len(nums)-1
            while i<j:
                m = (j-i+1)//2+i
                if nums[m] <= t: i=m
                else: j=m-1
            return j if nums[j] == t else -1
        
        l = lower_bound(target)
        r = upper_bound(target)
        return [l,r] if l != -1 and r != -1 else [-1,-1]

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return self.searchRange_2(nums,target)
        