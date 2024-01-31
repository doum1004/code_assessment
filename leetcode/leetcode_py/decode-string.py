'''
https://leetcode.com/problems/decode-string

1. Iterate and store str and num in list for later operation
time: o(n)
space: o(n)
1. digit: curNum = n*10 + c-'0'
2. alpha: curStr += c
3. '[': store curNum and curStr into list (nums, strs)
4. ']': store last 'nums' * curStr into last 'strs' list. st = strs[-] and pop both list
'''
class Solution:
    def decodeString(self, s: str) -> str:
        nums, strs = [], []
        curNum = 0
        curStr = ""
        for c in s:
            if c.isdigit():
                curNum = curNum * 10 + int(c)
            elif c.isalpha():
                curStr += c
            elif c == '[':
                nums.append(curNum)
                strs.append(curStr)
                curNum = 0
                curStr = ""
            elif c == ']':
                for i in range(nums[-1]):
                    strs[-1] += curStr
                curStr = strs[-1]
                strs.pop()
                nums.pop()

        return curStr
        