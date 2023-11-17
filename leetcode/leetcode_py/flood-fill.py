from typing import List

# https://leetcode.com/problems/flood-fill/

class Solution:
    def floodFill_DSF(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if len(image) < 1 or len(image[0]) < 1 or sr < 0 or sr >= len(image) or sc < 0 or sc >= len(image[0]):
            return image

        def dsf(image, r, c, refColor, newColor):
            if r < 0 or r >= len(image) or c < 0 or c >= len(image[0]) or image[r][c] != refColor or image[r][c] == newColor:
                return
            image[r][c] = newColor
            offset = [0,1,0,-1,0]
            for i in range(len(offset)-1):
                dsf(image,r+offset[i],c+offset[i+1],refColor,newColor)
            
        dsf(image, sr, sc, image[sr][sc], newColor)
        return image
     
    def floodFill_BSF(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if len(image) < 1 or len(image[0]) < 1 or sr < 0 or sr >= len(image) or sc < 0 or sc >= len(image[0]):
            return image
        #q = collections.deque([sr,sc])
        refColor = image[sr][sc]
        q = collections.deque()
        q.append([sr,sc])
        while q:
            r, c = q.popleft()
            if r<0 or c<0 or r>=len(image) or c>=len(image[0]) or image[r][c] != refColor or image[r][c] == newColor:
                continue
            image[r][c] = newColor
            
            offset = [0,1,0,-1,0]
            for i in range(len(offset)-1):
                q.append([r+offset[i], c+offset[i+1]])
        return image
        
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        #return self.floodFill_DSF(image, sr, sc, newColor)
        return self.floodFill_BSF(image, sr, sc, newColor)
        