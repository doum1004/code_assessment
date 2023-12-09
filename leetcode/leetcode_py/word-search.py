'''
https://leetcode.com/problems/word-search

Solution1. Backtracking (recursion, mark visited on map or board itself. give wordIdx to find next)
time: o(n*4^m) 4 times of words(4^m) * total board(n)
space: o(n) height
'''
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def findWord(s, i, j):
            if i < 0 or i == len(board) or j < 0 or j == len(board[0]): return False
            if board[i][j] != word[s]: return False
            if s == len(word) - 1: return True

            t = board[i][j]
            board[i][j] = ' '
            result = False
            if not result: result = findWord(s+1, i - 1, j)
            if not result: result = findWord(s+1, i + 1, j)
            if not result: result = findWord(s+1, i, j - 1)
            if not result: result = findWord(s+1, i, j + 1)
            board[i][j] = t
            return result
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if findWord(0, i, j): return True

        return False
        