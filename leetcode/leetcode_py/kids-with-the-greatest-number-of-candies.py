'''
https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
'''
class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        res = []
        m = 0
        for candy in candies:
            m = max(m, candy)
        for candy in candies:
            res.append(m <= candy + extraCandies)                
        return res
        