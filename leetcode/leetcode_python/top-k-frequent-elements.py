from typing import List

"""
https://leetcode.com/problems/top-k-frequent-elements/

"""

class Solution:
    def topKFrequent_heap(self, nums: List[int], k: int) -> List[int]:
        #count = collections.Counter(nums)
        count = {}
        for n in nums:
            if n in count:
                count[n] += 1
            else:
                count[n] = 1
        
        return heapq.nlargest(k, count.keys(), key=count.get)
    
    def topKFrequent_bucket(self, nums: List[int], k: int) -> List[int]:
        count = collections.Counter(nums)
        bucket = [[] for i in range(len(nums) + 1)]
        for key, value in count.items():
            bucket[value].append(key)
            
        res = []
        for i in range(len(nums), 0, -1):
            for n in bucket[i]:
                res.append(n)
                if len(res) == k:
                    return res
        
        return res
    
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #return self.topKFrequent_heap(nums, k)
        return self.topKFrequent_bucket(nums, k)