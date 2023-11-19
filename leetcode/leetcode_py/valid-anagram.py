'''
https://leetcode.com/problems/valid-anagram

Solution1. sort
time: o(nlogn)
space: o(1)

Solution2. map
time: o(1)
space: o(n)

Solution3. array
time: o(1)
space: o(1)
'''

class Solution:
    def isAnagram_1(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)

    def isAnagram_2(self, s: str, t: str) -> bool:
        m = defaultdict(int)
        for c in s:
            m[c] += 1
        for c in t:
            m[c] -= 1
        for val in m.values():
            if val != 0:
                return False
        return True

    def isAnagram_3(self, s: str, t: str) -> bool:
        arr = [0] * 26
        for c in s:
            arr[ord(c) - ord('a')] += 1
        for c in t:
            arr[ord(c) - ord('a')] -= 1
        for v in arr:
            if v != 0:
                return False
        return True

    def isAnagram(self, s: str, t: str) -> bool:
        return self.isAnagram_3(s, t)
        