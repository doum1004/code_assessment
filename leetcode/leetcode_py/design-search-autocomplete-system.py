from typing import List
import collections
import heapq

"""
https://leetcode.com/problems/design-search-autocomplete-system/submissions/
"""

class Trie:
    def __init__(self):
        self.children = {}
        self.sentence = ''
        self.count = 0
        #self.needToUpdate = True
    
    def addWord(self, s: str, count: int):
        trie = self
        for c in s:
            if c not in trie.children:
                trie.children[c] = Trie()
            trie = trie.children[c]
            #trie.needToUpdate = True
            
        trie.sentence = s
        trie.count += count
        
    def buildAutoCompletation(self, q, node):
        if node and node.count > 0:
            q.append((node.count, node.sentence))
            
        for k,v in node.children.items():
            self.buildAutoCompletation(q, v)
        
    def autoCompletation(self):
        #if self.needToUpdate:
        q = []
        self.buildAutoCompletation(q, self)
        result=heapq.nsmallest(3,q,key= lambda x:(-x[0],x[1])) # max heap to get top 3 
        return [word[1] for word in result]
        #return self.cache
    

class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.root = Trie()
        self.keyWord = ''
        for i in range(0, len(sentences)):
            self.root.addWord(sentences[i], times[i])
        self.cur = self.root

    def input(self, c: str) -> List[str]:
        if c == '#':
            self.root.addWord(self.keyWord,1)
            self.cur = self.root
            self.keyWord = ''
            return []
        
        self.keyWord += c
        if self.cur:
            self.cur = self.cur.children[c] if c in self.cur.children else None
        
        if self.cur:
            return self.cur.autoCompletation()
        else:
            return []


# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)