from typing import List
import collections

"""
https://leetcode.com/problems/word-ladder-ii/
"""

class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
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
        
        