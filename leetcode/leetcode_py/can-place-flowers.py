'''
https://leetcode.com/problems/can-place-flowers

Solution. Iterate and check condition
time: o(n)
space: o(1)
'''
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if n == 0: return True
        flowerbed.insert(0, 0)
        flowerbed.append(0)
        i = 1
        while i < len(flowerbed) - 1:
            if flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0:
                n -= 1
                if n == 0: return True
                i += 1
            i += 1

        return False
        
        