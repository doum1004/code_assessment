class Solution:
    def findKthLargest_1(self, nums: List[int], k: int) -> int:
        nums.sort()
        return nums[-k]
    
    def findKthLargest_2(self, nums: List[int], k: int) -> int:
        # https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/3906260/100-3-approaches-video-heap-quickselect-sorting/?envType=study-plan-v2&envId=top-interview-150
        heap = nums[:k]
        heapq.heapify(heap)
        
        for num in nums[k:]:
            if num > heap[0]:
                heapq.heappop(heap)
                heapq.heappush(heap, num)
        
        return heap[0]

    def findKthLargest(self, nums: List[int], k: int) -> int:
        return self.findKthLargest_2(nums, k)
        