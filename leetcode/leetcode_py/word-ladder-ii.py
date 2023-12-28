from typing import List
import collections

"""
https://leetcode.com/problems/word-ladder-ii/
"""

class Solution:
    def findLadders_1(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        dictionary = dict.fromkeys(wordList, 1)
        if endWord not in dictionary:
            return []
        
        def buildLadders(word, children, ladder, res):
            ladder.append(word)
            if word == endWord:
                res.append(list(ladder))
            else:
                for child in children[word]:
                    buildLadders(child, children, ladder, res)
            ladder.pop()
        
        word_current = collections.defaultdict(int)
        word_next = collections.defaultdict(int)
        
        res = []
        
        word_current[beginWord] = 1
        ladder = []
        
        children = collections.defaultdict(list)
        while (True):
            for word in word_current:
                if word in dictionary:
                    del dictionary[word]
                
            for parent in word_current:
                word = parent
                for i in range(0, len(word)):
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        word = word[:i] + c + word[i+1:]
                        if word in dictionary:
                            word_next[word] = 1
                            children[parent].append(word)
                        
                    word = parent
            if not len(word_next):
                break
                
            if endWord in word_next:
                buildLadders(beginWord, children, ladder, res)
                break
        
            word_current = dict(word_next)
            word_next.clear()
            
        return res
        
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        m = {}
        for word in wordList:
            m[word] = (0, set())
        m[beginWord] = (1, set())
        
        q = [beginWord]
        while q:
            w = q[0]
            q.pop(0)

            dist = m[w][0] + 1
            
            for i in range(len(w)):
                w2 = w
                for j in range(ord('a'), ord('z')+1):
                    w2 = w2[:i] + chr(j) + w2[i+1:]
                    if w2 in m and w2 != w:
                        if m[w2][0] == dist: m[w2][1].add(w)
                        elif m[w2][0] == 0 or m[w2][0] > dist:
                            m[w2] = (dist, m[w2][1])
                            m[w2][1].clear()
                            m[w2][1].add(w)
                            if w2 != endWord: q.append(w2)
        if endWord not in m or len(m[endWord][1]) == 0: return []
        
        res = []
        cur = []
        def build(word):
            cur.append(word)
            if len(m[word][1]) == 0: res.append(cur[:])
            else:
                for adj in m[word][1]:
                    build(adj)
            cur.pop()
        build(endWord)
        for r in res: r.reverse()
        return res
        
