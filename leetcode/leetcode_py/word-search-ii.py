from typing import List

class Solution:
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
                