from typing import List

class Solution:
    def canFinish_dfs_recursion(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        #build graph
        g = [[] for i in range(numCourses)]
        for i, j in prerequisites:
            g[j].append(i)
        
        v = [0] * numCourses
        def dfs(i):
            if v[i] == -1:
                return False
            if v[i] == 1:
                return True
            v[i] = -1
            for j in g[i]:
                if not dfs(j):
                    return False
            v[i] = 1
            return True
        
        for i in range(numCourses):
            if not dfs(i):
                return False
            
        return True
        
    def canFinish_bfs_interation(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # build graph
        g = [[] for i in range(numCourses)]
        indegree = [0] * numCourses
        for p in prerequisites:
            g[p[1]].append(p[0])
            indegree[p[0]] += 1
        
        bfs = []
        for i in range(numCourses):
            if (indegree[i] == 0):
                bfs.append(i)
                
        for i in bfs:
            for j in g[i]:
                indegree[j] -= 1
                if (indegree[j] == 0):
                    bfs.append(j)
                
        return len(bfs) == numCourses
        
    def canFinish_1(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        g = defaultdict(list)
        for p in prerequisites:
            g[p[0]].append(p[1])

        v = set()
        def hasCycle(innerV, node):
            if node in innerV: return True
            if node in v: return False
            v.add(node)
            innerV.add(node)
            for adj in g[node]:
                if hasCycle(innerV, adj): return True
            innerV.remove(node)
            return False

        for p in prerequisites:
            innerV = set()
            if hasCycle(innerV, p[0]): return False

        return True
        
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        #return self.canFinish_bfs_interation(numCourses, prerequisites)
        return self.canFinish_dfs_recursion(numCourses, prerequisites)
        