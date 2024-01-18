'''
https://leetcode.com/problems/keys-and-rooms

1. bfs (queue)
time: o(n)
space: o(n)
2. dfs
time: o(n)
space: o(n)
'''
class Solution:
    def canVisitAllRooms_dfs(self, rooms: List[List[int]]) -> bool:
        if len(rooms) <= 1: return True
        v = set()
        def dfs(i):
            if i in v: return
            v.add(i)
            for room in rooms[i]:
                dfs(room)
        dfs(0)
        return len(v) == len(rooms)

    def canVisitAllRooms_bfs(self, rooms: List[List[int]]) -> bool:
        if len(rooms) <= 1: return True
        v = set()
        q = [0]
        while q:
            key = q[0]
            q.pop(0)
            if key in v:
                continue
            v.add(key)
            for room in rooms[key]:
                q.append(room)
        return len(v) == len(rooms)

    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        return self.canVisitAllRooms_bfs(rooms)
        