'''
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

Solution1. stl find
time: o(n)
space: o(1)

Solution2. substr
time: o(n) m*n
space: o(1)

Solution3. KPM longest prefix and suffix
time: o(n) m+n
space: o(1)
https://youtu.be/0iDiUuHZE_g
'''
class Solution:
    def strStr_1(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)

    def strStr_2(self, haystack: str, needle: str) -> int:
        size1 = len(needle)
        for i in range(len(haystack)):
            if len(haystack) - i < size1:
                break
            if (haystack[i] == needle[0]):
                if haystack[i:size1 + i] == needle:
                    return i
                
        return -1

    def strStr_3(self, haystack: str, needle: str) -> int:
        lps = [0] * len(needle)
        pre = 0
        for i in range(1, len(needle)):
            while (pre > 0 and needle[i] != needle[pre]):
                pre = lps[pre - 1]
            if needle[i] == needle[pre]:
                pre += 1
                lps[i] = pre
        
        n = 0
        for i in range(len(haystack)):
            while (n > 0 and haystack[i] != needle[n]):
                n = lps[n - 1]
            if haystack[i] == needle[n]:
                n += 1
            if len(needle) == n:
                return i - n + 1
        return -1

            

    def strStr(self, haystack: str, needle: str) -> int:
        return self.strStr_3(haystack, needle)
        