'''
https://leetcode.com/problems/successful-pairs-of-spells-and-potions

1. brute force
time: n^m

2. sort and binary search
time: o(nlogn + mlogn)
space: o(1)
'''
class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        for i in range(len(spells)):
            spell = spells[i]
            l, r = 0, len(potions) - 1
            while l <= r:
                m = (r-l) // 2 + l
                if success <= potions[m] * spell:
                    r = m - 1
                else:
                    l = m + 1                
            spells[i] = len(potions) - r - 1

        return spells
        