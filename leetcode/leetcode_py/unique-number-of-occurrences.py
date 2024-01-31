'''
https://leetcode.com/problems/unique-number-of-occurrences

1. Using map and set
time: o(n)
space: o(n)
'''
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        m = defaultdict(int)
        s = set()
        for num in arr:
            m[num] += 1
        for key in m:
            if m[key] in s: return False
            s.add(m[key])
        return True
        