class Solution:
    def isValid(self, s: str) -> bool:
        m = {'}': '{', ')': '(', ']': '['}
        st = []
        for c in s:
            if c in m:
                if not len(st) or st[-1] != m[c]:
                    return False
                st.pop()
            else:
                st.append(c)
        return len(st) == 0
        