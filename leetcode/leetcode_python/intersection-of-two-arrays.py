from typing import List

"""
https://leetcode.com/problems/intersection-of-two-arrays/
"""

class Solution:
    def intersection_space1(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = {}
        for n in nums1:
            s1[n] = True
            
        res = []
        for n in nums2:
            if n in s1:
                res.append(n)
                del s1[n]
        return res
    
    def intersection_space2(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        s2 = set(nums2)
        return list(s1 & s2)
    
    def intersection_nospace(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        n1,n2 = len(nums1), len(nums2)
        res = []
        l,r=0,0
        while (True):
            while l<n1-1 and nums1[l] == nums1[l+1]: l +=1
            while r<n2-1 and nums2[r] == nums2[r+1]: r +=1
            
            if l<n1 and r<n2:
                if nums1[l] == nums2[r]:
                    res.append(nums1[l])
                    l +=1
                    r +=1
                elif nums1[l] < nums2[r]:
                    l +=1
                else:
                    r +=1
            else:  
                break
        return res
        
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        #return self.intersection_space1(nums1, nums2)
        #return self.intersection_space2(nums1, nums2)
        return self.intersection_nospace(nums1, nums2)