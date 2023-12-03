'''
https://leetcode.com/problems/evaluate-reverse-polish-notation

Solution1. Stack
time: o(n)
space: o(n)

Stack numbers and pop 2 nums for operation
'''
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        op = {
            '+': lambda x,y : x+y,
            '-': lambda x,y : x-y,
            '*': lambda x,y : x*y,
            '/': lambda x,y : int(x/y)
        }
        st = []
        for token in tokens:
            if token in op:
                v2 = st.pop()
                v1 = st.pop()
                st.append(op[token](v1,v2))
            else:
                st.append(int(token))
        return st[0]
        