'''
https://leetcode.com/problems/word-pattern

Solution1. hashmap
time: o(n)
space: o(n)

1. get list of string
2. store hashmap of char: string, string[char]. And compare them in iteration

'''
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        l = s.split()
        if len(pattern) != len(l):
            return False

        m1 = {}
        m2 = {}
        for i in range(len(pattern)):
            value1 = pattern[i]
            value2 = l[i]
            if value1 in m1 and m1[value1] != value2:
                return False
            if value2 in m2 and m2[value2] != value1:
                return False
            m1[value1] = value2
            m2[value2] = value1
        
        return True

        