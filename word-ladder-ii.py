'''
https://leetcode.com/problems/word-ladder-ii

BSF(gen next children) + DSF(generate ladder)
https://leetcode.com/problems/word-ladder-ii/discuss/241927/C%2B%2B-BFS-%2B-DFS
//time: o(n*L*26 + nlogn). build next (n*L*26) + build ladder (L*M == L*2^L == nlogn) O(L*M), where L is the length of the shortest path and M is the number of possible shortest paths.
//space:? o(n). graph(n) + children(n) + buildnext(n)

1. set dict set
2. BSF to gen next and children map from current
3. If next children has endWord, build ladders (DSF)
4. Else swap (cur, next)
'''
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        m = {}
        for word in wordList:
            m[word] = (0, set())
        m[beginWord] = (1, set())
        
        q = [beginWord]
        while q:
            w = q[0]
            q.pop(0)

            dist = m[w][0] + 1
            
            for i in range(len(w)):
                w2 = w
                for j in range(ord('a'), ord('z')+1):
                    w2 = w2[:i] + chr(j) + w2[i+1:]
                    if w2 in m and w2 != w:
                        if m[w2][0] == dist: m[w2][1].add(w)
                        elif m[w2][0] == 0 or m[w2][0] > dist:
                            m[w2] = (dist, m[w2][1])
                            m[w2][1].clear()
                            m[w2][1].add(w)
                            if w2 != endWord: q.append(w2)
        if endWord not in m or len(m[endWord][1]) == 0: return []
        
        res = []
        cur = []
        def build(word):
            cur.append(word)
            if len(m[word][1]) == 0: res.append(cur[:])
            else:
                for adj in m[word][1]:
                    build(adj)
            cur.pop()
        build(endWord)
        for r in res: r.reverse()
        return res
        


