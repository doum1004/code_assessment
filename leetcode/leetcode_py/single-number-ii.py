'''
https://leetcode.com/problems/single-number-ii

Solutions1. hashmap
time: o(n)
space: o(n)

Solutions2. sort and check
time: o(nlogn)
space: o(1)

Solutions3. Bitmanipluation
time: o(n) 32n
space: o(1)
'''
class Solution:
    def singleNumber_1(self, nums: List[int]) -> int:
        m = defaultdict(int)
        for n in nums:
            m[n] += 1
        
        for k in m:
            if m[k] == 1:
                return k
        return -1

    def singleNumber_3(self, nums: List[int]) -> int:
        res = 0
        for i in range(32):
            count = 0
            b = 1 << i
            for n in nums:
                if b & n:
                    count += 1
            if count % 3:
                res |= b
        return res

    def singleNumber(self, nums: List[int]) -> int:
        return self.singleNumber_3(nums)
        