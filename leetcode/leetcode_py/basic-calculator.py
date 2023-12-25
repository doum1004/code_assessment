'''
https://leetcode.com/problems/basic-calculator

Solution2. Stack
https://leetcode.com/problems/basic-calculator/solutions/62377/16-ms-solution-in-c-with-stacks/?envType=study-plan-v2&envId=top-interview-150
time: o(n)
space: o(n)
'''
class Solution:
    def calculate(self, s: str) -> int:
        ns, os = [], []
        total = 0
        num, sign = 0, 1
        for c in s:
            if c.isnumeric():
                num = num * 10 + int(c)
            else:
                total += num * sign
                num = 0
                if c == '+': sign = 1
                elif c == '-': sign = -1
                elif c == '(':
                    ns.append(total)
                    os.append(sign)
                    total = 0
                    sign = 1
                elif c == ')':
                    total = os[-1] * total + ns[-1]
                    os.pop()
                    ns.pop()
        total += num * sign
        return total
        