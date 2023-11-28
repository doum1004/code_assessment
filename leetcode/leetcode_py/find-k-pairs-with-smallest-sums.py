'''
https://leetcode.com/problems/find-k-pairs-with-smallest-sums

Solution. min heap
time: o(klogn)
space: o(n)

ex) [1, 7, 11] [2, 4, 6]
(3 (0,0)) (9 (1, 0)) (13 (2, 0)) -> pop: (3 (0,0))
(9 (1, 0)) (13 (2, 0)) -> push: (5, (0, 1))
(5, (0, 1)) (9 (1, 0)) (13 (2, 0)) -> pop (5, (0,1))
(9 (1, 0)) (13 (2, 0)) -> push: (7, (0, 2))
(7, (0, 2)) (9 (1, 0)) (13 (2, 0)) -> pop (7, (0,2))
(9 (1, 0)) (13 (2, 0)) -> pop (9, (1,0))
(13 (2, 0)) -> push: (11, (1, 1))
(11, (1, 1)) (13 (2, 0)) -> pop (11, (1,1))

'''
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        n1 = len(nums1)
        n2 = len(nums2)
        
        heap = [(nums1[i] + nums2[0], i, 0) for i in range(n1)]
        heapq.heapify(heap)
        res = []
        while k and heap:
            k -= 1
            s, i, j = heapq.heappop(heap)
            res.append([nums1[i], nums2[j]])

            if j + 1 < n2:
                heapq.heappush(heap, (nums1[i] + nums2[j+1], i, j + 1))
        return res