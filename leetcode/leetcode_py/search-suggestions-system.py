from typing import List
import bisect

"""
https://leetcode.com/problems/search-suggestions-system

3. Trie with Cache
time: ?? o(n) 26 * lenth of word * nb product
space: ?? o(n+m) n (26*maxChar of product * nb product) m(n*number of product)
"""

class Trie:
    def __init__(self):
        self.dict = [None] * 26
        self.cache = []
    
    def addProduct(self, product):
        cur = self
        for c in product:
            if not cur.dict[ord(c)-ord('a')]:
                cur.dict[ord(c)-ord('a')] = Trie()
            cur = cur.dict[ord(c)-ord('a')]
            cur.cache.append(product)

    def suggestions(self):
        self.cache.sort()
        res = []
        for word in self.cache:
            res.append(word)
            if len(res) == 3:
                break
        return res


class Solution:
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
    
    def suggestedProducts_trie(self, products: List[str], searchWord: str) -> List[List[str]]:
        root = Trie()
        for product in products:
            root.addProduct(product)

        res = []
        cur = root
        for c in searchWord:
            if cur: cur = cur.dict[ord(c)-ord('a')]
            if cur: res.append(cur.suggestions())
            else: res.append([])
        return res
                
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        #return self.suggestedProducts_sort(products,searchWord)
        return self.suggestedProducts_trie(products,searchWord)
        