'''
Solution1. In place array

Time:
addWord: o(n) N is the length of the word being added
search(string word): o(m) M is the total number of nodes in the Trie.
Space: O(M), where M is the total number of nodes in the Trie
'''
class WordDictionary:

    def __init__(self):
        self.children = {}
        self.isLeaf = False
        
    def addWord(self, word: str) -> None:
        node = self
        for c in word:
            if not c in node.children:
                node.children[c] = WordDictionary()
            node = node.children[c]
        node.isLeaf = True

    def search(self, word: str) -> bool:                    
        return self.find(word, 0)
        
    def find(self, word, i):
        if i >= len(word):
            return self.isLeaf
        c = word[i]
        if c != '.':
            if not c in self.children:
                return False
            return self.children[c].find(word, i+1)
        else:
            for c in self.children:
                if self.children[c].find(word, i+1):
                    return True
        return False


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)