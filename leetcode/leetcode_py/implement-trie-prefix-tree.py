'''
https://leetcode.com/problems/implement-trie-prefix-tree

Solution. Build Tries in place (array, hashmap). 
time
- insert: o(n)
- search: o(n)
- startWith: o(n)
space: o(n)
'''
class Trie:

    def __init__(self):
        self.children = {}
        self.isLeaf = False

    def insert(self, word: str) -> None:
        node = self
        for c in word:
            if not c in node.children:
                node.children[c] = Trie()
            node = node.children[c]
        node.isLeaf = True
        
    def search(self, word: str) -> bool:
        node = self
        for c in word:
            if not c in node.children:
                return False
            node = node.children[c]
        return node.isLeaf        

    def startsWith(self, prefix: str) -> bool:
        node = self
        for c in prefix:
            if not c in node.children:
                return False
            node = node.children[c]
        return True        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)