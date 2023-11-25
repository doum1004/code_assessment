'''
https://leetcode.com/problems/snakes-and-ladders

Soltuion1. BSF
time: o(n^2) o(v+e) = v(7n^2)
space: o(n^2)

1. Build cells to contain actual number with board row, col to track easier
2. make visit list to store marking it is visited and many steps
3. BSF queue to store next visit
4. From queue pop, find next move + (1 ~ min(6, n^2))
5. If it has ladder, put it as dst else keep the same as next
6. check visit list, if not keep the step and push into queue to next iteration
'''
class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        cells = [0] * (n * n + 1)
        cols = [i for i in range(n)]
        
        num = 1
        for row in range(n-1, -1, -1):
            for col in cols:
                cells[num] = [row, col]
                num += 1
            
            cols = cols[::-1]
        
        visited = [-1] * (n*n+1)
        visited[1] = 0
        q = []
        q.append(1)
        
        while q:
            qSize = len(q)
            for i in range(qSize):
                cur = q.pop(0)
                maxNext = min(cur+6, n*n)
                for next in range(cur+1, maxNext+1):
                    r, c = cells[next]
                    dest = next
                    if board[r][c] != -1:
                        dest = board[r][c]
                        
                    if visited[dest] == -1:
                        visited[dest] = visited[cur] + 1
                        q.append(dest)
 
        return visited[n*n]
        