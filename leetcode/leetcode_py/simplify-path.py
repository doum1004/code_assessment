'''
https://leetcode.com/problems/simplify-path

Solution1. stack
time: o(n)
space: o(n)

1. iterate path
2. add strings into temp
3. if it hits '/' check conditions of temp
- '..' pop the last (stack needed)
- '.' or '' skip
- clean temp
- continue iteration
4. iterate stack to build answer
'''

class Solution:
    def simplifyPath(self, path: str) -> str:
        path += "/"
        l = []
        temp = ""
        for c in path:
            if c == "/":
                if temp == "..":
                    if l: l.pop()
                elif temp != "." and temp != "":
                    l.append(temp)
                temp = ""
                continue
            temp += c
        
        res = ""
        for value in l:
            res += "/" + value        
        return res if res != "" else "/"