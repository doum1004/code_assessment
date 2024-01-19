'''
https://leetcode.com/problems/kth-largest-element-in-an-array

1. sort, nth_element, partial sort
time: o(nlogn)
space: o(1)

2. priority_queue
time: o(nlogn)
space: o(n)

3. quick selection
https://www.youtube.com/watch?v=XEmy13g1Qxc
time: o(n^2) best o(n)
space: o(n)
'''
class Solution:
    def findKthLargest_1(self, nums: List[int], k: int) -> int:
        nums.sort()
        return nums[len(nums)-k]

    def findKthLargest_2(self, nums: List[int], k: int) -> int:
        # min heap
        heap = []
        for num in nums:
            heapq.heappush(heap, num)
            if len(heap) > k:
                heapq.heappop(heap)
        return heap[0]

    def findKthLargest_3(self, nums: List[int], k: int) -> int:
        l, r = 0, len(nums)-1
        def partition(l1, r1):
            if l1 == r1:
                return l1
            idx = l1
            for i in range(l1, r1):
                if nums[i] > nums[r1]:
                    nums[i], nums[idx] = nums[idx], nums[i]
                    idx += 1
            nums[idx], nums[r1] = nums[r1], nums[idx]
            return idx
        while l <= r:
            pivot = partition(l, r)
            if pivot == k - 1:
                return nums[pivot]
            elif pivot < k - 1:
                l = pivot + 1
            else:
                r = pivot - 1
        return -1
        
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return self.findKthLargest_2(nums, k)
        