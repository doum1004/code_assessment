'''
https://leetcode.com/problems/zigzag-conversion

Solution. Traverse and store on level
time: o(n)
space: o(n)
'''
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        dir = True
        level = 0
        slot = [""] * numRows
        for c in s:
            slot[level] += c
            level += 1 if dir else -1
            if level == numRows-1 or level == 0:
                dir = not dir

        res = ""
        for values in slot:
            res += values
        return res
        