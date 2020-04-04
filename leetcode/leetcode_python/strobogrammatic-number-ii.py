from typing import List
import collections

"""
https://leetcode.com/problems/strobogrammatic-number-ii/
"""

class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        def find(m, n):
            if m == 0: return [""]
            if m == 1: return ["0", "1", "8"]
            tmp = find(m-2, n)
            res = []
            for i in range(len(tmp)):
                if n != m: res.append("0" + tmp[i] + "0")
                res.append("1" + tmp[i] + "1")
                res.append("6" + tmp[i] + "9")
                res.append("8" + tmp[i] + "8")
                res.append("9" + tmp[i] + "6")
            return res
        return find(n,n)
        