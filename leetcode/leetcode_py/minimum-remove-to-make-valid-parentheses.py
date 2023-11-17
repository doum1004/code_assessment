from typing import List

"""
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/submissions/
"""

class Solution:
    def minRemoveToMakeValid_stack(self, s: str) -> str:
        st = []
        i = 0
        while i < len(s):
            if s[i] == '(':
                st.append(i)
            elif s[i] == ')':
                if st:
                    st.pop()
                else:
                    s = s[:i] + s[i+1:]
                    i -= 1
            i += 1
        
        while st:
            i = st.pop()
            s = s[:i] + s[i+1:]
            
        return s
        
        
    def minRemoveToMakeValid_nospace(self, s: str) -> str:
        balance = 0
        s = list(s)
        
        for i, c in enumerate(s):
            if c == '(': balance += 1
            elif c == ')':
                if not balance: s[i] = ""
                else: balance -= 1
                    
        for i in range(len(s)-1, -1, -1):
            if not balance: break
            if s[i] == '(': s[i] = ""; balance -= 1
            
        return "".join(s)
    
    def minRemoveToMakeValid(self, s: str) -> str:
        #return self.minRemoveToMakeValid_stack(s)
        return self.minRemoveToMakeValid_nospace(s)
        