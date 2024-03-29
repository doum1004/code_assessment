from typing import List

"""
https://leetcode.com/problems/game-of-life/
"""

class Solution:
    def deadOrLive(self, board, r, c):
        n_r = len(board)
        n_c = len(board[0])
        cur = abs(board[r][c])
        count = 0
        
        offset = [[0,1], [1,0], [0,-1], [-1,0], [-1,-1], [-1,1], [1,-1], [1,1]]
        for x, y in offset:
            row = r + x
            col = c + y
            if row < 0 or col < 0 or row >= n_r or col >= n_c:
                continue
            count += abs(board[row][col]) == 1
            #print(r, c, count)
        
        result = False
        if cur == 1:
            result = (count == 2 or count == 3)
        else:
            result = count == 3
        #print(cur, count, result)
        return result
                        
    def gameOfLife_copy(self, board: List[List[int]]) -> None:
        if len(board) < 1 or len(board[0]) < 1:
            return
        
        n_r = len(board)
        n_c = len(board[0])
        
        b = [[board[row][col] for col in range(n_c)] for row in range(n_r)]
        for r in range(n_r):
            for c in range(n_c):
                board[r][c] = 1 if self.deadOrLive(b, r, c) else 0
                
                
    def gameOfLife_inplace(self, board: List[List[int]]) -> None:
        if len(board) < 1 or len(board[0]) < 1:
            return
        
        def update(row, col):
            pre = board[row][col]
            result = self.deadOrLive(board, row, col)
            if pre == 1 and not result:
                board[row][col] = -1
            if pre == 0 and result:
                board[row][col] = 2
                            
        n_r = len(board)
        n_c = len(board[0])
        
        for r in range(n_r):
            for c in range(n_c):
                update(r, c)
                
        for r in range(n_r):
            for c in range(n_c):
                if board[r][c] == 2:
                    board[r][c] = 1
                elif board[r][c] == -1:
                    board[r][c] = 0
        
    def gameOfLife_3(self, board: List[List[int]]) -> None:
        m = len(board)
        n = len(board[0])
        def liveCount(i, j):
            if i < 0 or i >= m or j < 0 or j >= n:
                return 0
            return 1 if abs(board[i][j]) == 1 else 0

        def updateBoard(i, j):
            v = 0
            v += liveCount(i-1, j-1)
            v += liveCount(i-1, j)
            v += liveCount(i-1, j+1)
            v += liveCount(i, j-1)
            v += liveCount(i, j+1)
            v += liveCount(i+1, j-1)
            v += liveCount(i+1, j)
            v += liveCount(i+1, j+1)
            if board[i][j] == 1:
                if v < 2 or v > 3:
                    board[i][j] = -1
            else:
                if v == 3:
                    board[i][j] = 2
        
        for i in range(m):
            for j in range(n):
                updateBoard(i,j)
        
        for i in range(m):
            for j in range(n):
                if board[i][j] == -1:
                    board[i][j] = 0
                elif board[i][j] == 2:
                    board[i][j] = 1
        
    def gameOfLife(self, board: List[List[int]]) -> None:
        #return self.gameOfLife_copy(board)
        #return self.gameOfLife_inplace(board)
        return self.gameOfLife_3(board)
        