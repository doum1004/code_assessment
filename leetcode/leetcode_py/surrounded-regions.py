'''
https://leetcode.com/problems/surrounded-regions

Solution1. DFS. Mark Visit and check it is surrounded well
time: o(n) n + n
space: o(n) n + n

1. iterate board
2. In loop, skip if node is not 'O' ('x' or 'v')
3. In dfs, return false if it exceeds boudnary. return true if 'x' or 'y'. mark 'V' and visit all adjacent nodes.
4. if dfs pass. trun 'v' to 'x'
5. loop again convert 'v' to 'o'

Solution2. DFS. In place. Mark all edge connections '#' and convert 'O' to 'X' '#' to 'O'
time: o(n) n + n
space: o(n) n

1. iterate row edges and call bsf to mark mark '#'
2. same for col edges
3. iterate all board, convert 'o' to 'x' and convert '#' to 'o'
'''

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n1 = len(board)
        if n1 == 0:
            return
        n2 = len(board[0])
        if n2 == 0:
            return
        def dfs(row, col):
            if row < 0 or col < 0 or row >= n1 or col >= n2 or board[row][col] != 'O':
                return
            board[row][col] = '#'
            dfs(row+1,col)
            dfs(row-1,col)
            dfs(row,col+1)
            dfs(row,col-1)

        for i in range(n1):
            if board[i][0] == 'O':
                dfs(i, 0)
            if board[i][n2-1] == 'O':
                dfs(i, n2-1)

        for j in range(n2):
            if board[0][j] == 'O':
                dfs(0, j)
            if board[n1-1][j] == 'O':
                dfs(n1-1, j)

        for i in range(n1):
            for j in range(n2):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == '#':
                    board[i][j] = 'O'
        
            
        