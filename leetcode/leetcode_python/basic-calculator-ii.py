class Solution:
    def calculate(self, s: str) -> int:
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
                
        