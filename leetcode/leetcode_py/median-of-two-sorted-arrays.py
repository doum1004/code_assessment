'''
https://leetcode.com/problems/median-of-two-sorted-arrays

Solution1. Sort
time: o(nlogm)
space: o(n)

Solution2. Two Pointers
time: o(n)
space: o(n)

1 2 3 4 % 2 = 00
-> (2 + 3) / 2
1 2 3
-> 2

Solution3. Binary search (TODO)
https://www.youtube.com/watch?v=LPFhl65R7ww
time: o(logn)
space: o(1)
'''
class Solution:
    def findMedianSortedArrays_1(self, nums1: List[int], nums2: List[int]) -> float:
        for num in nums2:
            nums1.append(num)
        nums1.sort()
        n = len(nums1)
        if n % 2 == 0:
            return (nums1[n//2-1] +nums1[n//2]) / 2
        else:
            return nums1[n//2]
    def findMedianSortedArrays_2(self, nums1: List[int], nums2: List[int]) -> float:
        nums = []
        l, r = 0, 0
        while l < len(nums1) and r < len(nums2):
            if nums1[l] < nums2[r]:
                nums.append(nums1[l])
                l += 1
            else:
                nums.append(nums2[r])
                r += 1
        while l < len(nums1):
            nums.append(nums1[l])
            l += 1
        while r < len(nums2):
            nums.append(nums2[r])
            r += 1
        n = len(nums)
        if n % 2 == 0:
            return (nums[n//2-1] +nums[n//2]) / 2
        else:
            return nums[n//2]
    def findMedianSortedArrays_3(self, nums1: List[int], nums2: List[int]) -> float:
        n1 = len(nums1)
        n2 = len(nums2)
        if n1 > n2: return self.findMedianSortedArrays_3(nums2, nums1)
        
        l, r = 0, n1
        while l<=r:
            px = (l+r) // 2
            py = (n1 + n2 + 1) // 2 - px
            
            x1 = float(-inf) if px == 0 else nums1[px-1]
            x2 = float(inf) if px == n1 else nums1[px]
            y1 = float(-inf) if py == 0 else nums2[py-1]
            y2 = float(inf) if py == n2 else nums2[py]
            
            if x1 <= y2 and y1 <= x2:
                if (n1 + n2) % 2 == 0:
                    return (max(x1, y1) + min(x2, y2)) / 2
                else:
                    return max(x1, y1)
            elif x1 <= y2:
                l = px + 1
            else:
                r = px - 1
        return -1
        
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        return self.findMedianSortedArrays_3(nums1, nums2)
        
        