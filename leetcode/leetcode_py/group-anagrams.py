'''
https://leetcode.com/problems/group-anagrams

Solution1. Sort
time: o(nlogn) nlogn + n
space: o(n)
'''
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        n = len(strs)
        if n == 1:
            return [strs]
        
        m = defaultdict(list)
        for s in strs:
            m[''.join(sorted(s))].append(s)
        
        res = []
        for key in m:
            res.append(m[key])

        return res