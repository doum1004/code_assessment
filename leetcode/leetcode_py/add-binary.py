'''
https://leetcode.com/problems/add-binary
'''
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i = len(a) - 1
        j = len(b) - 1
        sum = 0
        res = []

        while i>=0 or j>=0 or sum:
            if i>=0:
                sum += int(a[i])
                i -= 1
            if j>=0:
                sum += int(b[j])
                j -= 1
            res.append(str(sum % 2))
            sum //= 2
            
        return ''.join(reversed(res))