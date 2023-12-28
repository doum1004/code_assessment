'''
https://leetcode.com/problems/word-ladder

Soltuion1. BFS with transformed map
time: o(n*wordsize + n)
space: o(n*wordSize)

Soltuion2. BFS with set
time: o(n*wordsize + n)
space: o(n)
'''
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        s = set()
        for word in wordList:
            s.add(word)
        if not endWord in s:
            return 0
        q = [(beginWord, 1)]
        while q:
            w = q[0][0]
            l = q[0][1]
            q.pop(0)
            
            for i in range(len(w)):
                for j in range(ord('a'), ord('z') + 1):
                    c = chr(j)
                    w2 = w[:i] + c + w[i+1:]
                    if w2 == endWord: return l + 1
                    if w2 in s:
                        q.append((w2, l+1))
                        s.remove(w2)

        return 0