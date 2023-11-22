'''
https://leetcode.com/problems/spiral-matrix/

// Solution1. visit node with visited board
// time: o(n)
// space: o(n). visited(n). queue(1)

// Solution2. layer by layer
Loop for each layers(top layer, right layer, bottom layer, left layer) till end
// time: o(n)
// space: o(1)
'''
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n_row = len(matrix)
        if n_row == 0:
            return []
        if n_row == 1:
            return matrix[0]

        n_col = len(matrix[0])
        l, r = 0, n_col - 1
        t, b = 0, n_row - 1
        res = []
        while (l <= r and t <= b):
            for i in range(l, r + 1):
                res.append(matrix[t][i])
            t += 1
            for i in range(t, b + 1):
                res.append(matrix[i][r])
            r -= 1

            if not (l <= r and t <= b):
                break

            for i in range(r, l - 1, -1):
                res.append(matrix[b][i])
            b -= 1
                
            for i in range(b, t - 1, -1):
                res.append(matrix[i][l])

            l += 1

        return res        
                

            
        
        