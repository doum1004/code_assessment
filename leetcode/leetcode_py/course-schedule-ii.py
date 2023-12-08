'''
https://leetcode.com/problems/course-schedule-ii

Solution1. DFS (hashmap for graph and cache for visit and inner visit)
time: o(n) graph, recursion
space: o(n) graph, visited, recursion
'''
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        g = defaultdict(list)
        v = set()
        res = []
        def hasCycle(innerV, node) -> bool:
            if node in innerV: return True
            if node in v: return False
            v.add(node)
            innerV.add(node)   
            for adj in g[node]:
                if hasCycle(innerV, adj): return True         
            innerV.remove(node)
            res.append(node)
            return False

        for p in prerequisites:
            g[p[0]].append(p[1])

        for p in prerequisites:
            innerV = set()
            if hasCycle(innerV, p[0]): return []

        if len(res) != numCourses:
            for i in range(numCourses):
                if len(res) == numCourses: break
                res.append(i)

        return res
        