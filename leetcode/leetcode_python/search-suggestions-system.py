from typing import List
import bisect

"""
https://leetcode.com/problems/search-suggestions-system/submissions/
"""

class Trie:
    def __init__(self):
        self.children = {}
        self.string = ''
        self.cache = []
    
    def addWord(self, s):
        trie = self
        for c in s:
            if c not in trie.children:
                trie.children[c] = Trie()
            trie = trie.children[c]
            trie.cache.append(s)
            
        trie.string = s
    
    def search(self, keyword):
        trie = self
        for c in keyword:
            trie = trie.children[c] if trie and c in trie.children else None
            
        res = trie.cache if trie else []
        res.sort()
        
        return res[:3]

class Solution:
    def suggestedProducts_trie(self, products: List[str], searchWord: str) -> List[List[str]]:
        root = Trie()
        for product in products:
            root.addWord(product)
            
        res = []
        s = ''
        for c in searchWord:
            s += c
            res.append(root.search(s))
            
        return res
        
    def suggestedProducts_sort(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        res = []
        s = ''
        i = 0
        for c in searchWord:
            s += c
            i = bisect.bisect_left(products, s, i)
            suggestion = [w for w in products[i:i+3] if w.startswith(s)]
            # for p in products[i:i+3]:
            #     if p.startswith(s):
            #         suggestion.append(p)
            res.append(suggestion)
            
        return res
    
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        #return self.suggestedProducts_trie(products,searchWord)
        return self.suggestedProducts_sort(products,searchWord)
        