from typing import List
import collections

"""
https://leetcode.com/problems/cut-off-trees-for-golf-event/submissions/
"""

class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        trees = sorted((v,r,c) for r, row in enumerate(forest) for c, v in enumerate(row) if v > 1)
        m,n = len(forest), len(forest[0])
        def bsf(sr, sc, tr, tc):
            if sr == tr and sc == tc: return 0
            q = collections.deque([(sr,sc,0)])
            seen = {(sr,sc)}
            while q:
                r, c, d = q.popleft()
                if r == tr and c == tc: return d
                
                for nr, nc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                    if (0 <= nr and 0 <= nc and nr < m and nc < n and (nr,nc) not in seen and forest[nr][nc]):
                        seen.add((nr, nc))
                        q.append((nr, nc, d+1))
            return -1
            
        s_r = s_c = ans = 0 
        for _, t_r, t_c in trees:
            result = bsf(s_r, s_c, t_r, t_c)
            if result == -1: return -1
            ans += result
            s_r = t_r
            s_c = t_c
            
        return ans
            
        