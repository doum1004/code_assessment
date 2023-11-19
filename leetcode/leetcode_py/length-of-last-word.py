class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        res = 0
        for i in range(len(s) - 1, -1, -1):
            c = s[i]
            if c == ' ':
                break
            else:
                res += 1

        return res

        