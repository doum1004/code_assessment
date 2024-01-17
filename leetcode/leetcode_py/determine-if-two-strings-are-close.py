'''
https://leetcode.com/problems/determine-if-two-strings-are-close

1. list and sort
time: o(nlogn) n(word size) + nlogn (26log26)
Swap or Replace all occurence
has to meet
1. same frequency (no matter chars)
ex) a:4, b:1 == b:4, a:1
2. same set values (that can replace or swap)
ex) a,b == a,b
'''
class Solution:
    def closeStrings_1(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2): return False
        c1 = [0] * 26
        c2 = [0] * 26
        for i in range(len(word1)):
            c1[ord(word1[i])-ord('a')] += 1
            c2[ord(word2[i])-ord('a')] += 1
        for i in range(26):
            if (c1[i] and not c2[i]) or (not c1[i] and c2[i]):
                return False
        c1.sort()
        c2.sort()
        return c1 == c2

    def closeStrings_2(self, word1: str, word2: str) -> bool:
        s1 = set(word1)
        s2 = set(word2)
        if s1 != s2:
            return False
        c1 = sorted(Counter(word1).values())
        c2 = sorted(Counter(word2).values())
        return c1 == c2

    def closeStrings(self, word1: str, word2: str) -> bool:
        return self.closeStrings_2(word1, word2)