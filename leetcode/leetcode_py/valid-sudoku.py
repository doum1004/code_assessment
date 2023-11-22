'''
https://leetcode.com/problems/valid-sudoku

Solutions1. Brute force with hash map or array
time: o(n)
space: o(n) r + c + board
'''
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        hor = defaultdict(set)
        ver = defaultdict(set)
        sqr = defaultdict(set)
        for i in range(9):
            for j in range(9):
                c = board[i][j]
                if c != '.':
                    if c in hor[j] or c in ver[i] or c in sqr[i//3,j//3]:
                        return False
                    hor[j].add(c)
                    ver[i].add(c)
                    sqr[i//3,j//3].add(c)
        return True
