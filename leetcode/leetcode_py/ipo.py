'''
https://leetcode.com/problems/ipo

Soltuion1. Brute force
time: o(n^3)
space: o(1)

Solution2. max heap
time: o(nlogn) nlogn + klogn
space: o(n) n + n
vector<pair<captial, profit>> v; sort for captial <= w
priority_queue<int> max heap to get most profits
'''
class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        n = len(profits)
        projects = []
        for i in range(n):
            projects.append((capital[i], profits[i]))
        projects.sort()
        i = 0
        maxHeap = []
        while k:
            while i < n and projects[i][0] <= w:
                heapq.heappush(maxHeap, -projects[i][1])
                i += 1
            if not maxHeap:
                break
            w += -heapq.heappop(maxHeap)
            k -= 1
        return w
        