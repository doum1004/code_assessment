from typing import List
'''
https://leetcode.com/problems/word-search-ii

// Solution1. Backtracking(DSF) with Trie
// time: o( m ( 4*3^(L-1) )). m(board) L(length of word)
// space: o(w + L). w(words in tires) + L(length of word. recursion)
'''
class Solution1:
    def find(self, board, trie, r, c, word, res):
        if r<0 or c<0 or r>=len(board) or c>=len(board[0]) or board[r][c] == '*' or not board[r][c] in trie:
            return
        
        temp = board[r][c]
        board[r][c] = '*'
        
        trie = trie[temp]
        word += temp
        if ('#' in trie):
            res.append(word)
            del trie['#']
            
        offset = [0,1,0,-1,0]
        for i in range(4):
            self.find(board, trie, r+offset[i], c+offset[i+1], word, res)
        board[r][c] = temp
        
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        #Build trie
        trie = {}
        for w in words:
            t = trie
            for c in w:
                if c not in t:
                    t[c] = {}
                t=t[c]
            t['#'] = '#'
        res = []
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.find(board, trie, i, j, '', res)
                
        return res

class Trie:
    def __init__(self):
        self.isWord = False
        self.children = {}
    def addWord(self, word):
        cur = self
        for c in word:
            if c not in cur.children: cur.children[c] = Trie()
            cur = cur.children[c]
        cur.isWord = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # build trie
        root = Trie()
        for word in words: root.addWord(word)

        res = []
        def dfs(i, j, node, cur):
            if i < 0 or j < 0 or i>= len(board) or j>=len(board[0]) or board[i][j] == '#': return
            t = board[i][j]
            if t not in node.children: return

            cur += t
            node = node.children[t]
            if node.isWord:
                res.append(cur)
                node.isWord = False

            board[i][j] = '#'

            dfs(i-1, j, node, cur)
            dfs(i, j-1, node, cur)
            dfs(i+1, j, node, cur)
            dfs(i, j+1, node, cur)

            board[i][j] = t
            

        for i in range(len(board)):
            for j in range(len(board[0])):
                dfs(i, j, root, "")
                
        return res
        