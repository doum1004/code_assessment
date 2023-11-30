'''
https://leetcode.com/problems/h-index

Solution1. brute force
time: o(n^2)
space: o(1)

Solution2. sort
time: o(nlogn)
space: o(1)

1. sort
2. iterate from end and find value in index(n-h-1) is at leasst h or not

Solution3. hash table
time: o(n)
space: o(n)
'''
class Solution:
    def hIndex_1(self, citations: List[int]) -> int:
        n = len(citations)
        for i in range(n, 0, -1):
            cnt = 0
            for num in citations:
                if num >= i:
                    cnt += 1
                if cnt == i:
                    return i
        return 0
            
    def hIndex_2(self, citations: List[int]) -> int:
        n = len(citations)
        citations.sort()
        for i in range(n, 0, -1):
            if citations[n-i] >= i:
                return i
        return 0
            
    def hIndex_3(self, citations: List[int]) -> int:
        n = len(citations)
        h = [0] * (n+1)
        for num in citations:
            if num >= n:
                h[n] += 1
            else:
                h[num] += 1
        cnt = 0
        for i in range(n, 0, -1):
            cnt += h[i]
            if cnt >= i:
                return i
        return 0

    def hIndex(self, citations: List[int]) -> int:
        return self.hIndex_3(citations)
        