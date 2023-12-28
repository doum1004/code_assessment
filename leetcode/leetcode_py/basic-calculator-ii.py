'''
https://leetcode.com/problems/basic-calculator-ii/

// Solution1. Put result on stack
// time: o(n)
// space: o(n)

'''
class Solution:class Solution:
    def calculate_stack(self, s: str) -> int:
        ns = []
        num = 0
        sign = '+'
        for i, c in enumerate(s):
            if c.isnumeric():
                num = num * 10 + int(c)

            if (not c.isnumeric() and not c.isspace()) or i == len(s) - 1:
                if sign == '+': ns.append(num)
                elif sign == '-': ns.append(-num)
                else:
                    pre = ns[-1]
                    ns.pop()
                    if sign == '*':
                        ns.append(pre * num)
                    elif sign == '/':
                        ns.append(int(pre / num))
                sign = c
                num = 0
        res = 0
        while ns:
            res += ns[-1]
            ns.pop()
        return res
        
    def calculate_nostack(self, s: str) -> int:
        if not s:
            return 0
        
        def getNext(s: str, i: int):
            num = 0
            while i<len(s) and s[i] not in '-+*/':
                if s[i].isdigit():
                    num = num*10+ord(s[i])-ord('0')
                i += 1
            return (num, i)
        
        total = 0
        num, i = getNext(s, 0)
        sign = 1
        while (i<len(s)):
            if s[i] == '+':
                total += num * sign
                sign = 1
                num, i = getNext(s, i+1)
            elif s[i] == '-':
                total += num * sign
                sign = -1
                num, i = getNext(s, i+1)
            elif s[i] == '*':
                n, i = getNext(s, i+1)
                num *= n
            elif s[i] == '/':
                n, i = getNext(s, i+1)
                num = int(num/n)
        total += num * sign
        return total
                
    def calculate(self, s: str) -> int:
        return self.calculate_nostack(s)