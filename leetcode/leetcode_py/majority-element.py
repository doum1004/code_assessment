'''
https://leetcode.com/problems/majority-element/

Solution1. sort
time: o(nlogn)
space: o(1)

Soltuion2. map
time: o(n)
space: o(n)

Solution3. bit manipulation
time: o(n) 32*n
space: o(1)

Solution4. moore voting
time: o(n)
space: o(1)
'''
class Solution:
    def majorityElement_1(self, nums: List[int]) -> int:
        return sorted(nums)[len(nums) // 2]

    def majorityElement_2(self, nums: List[int]) -> int:
        m = defaultdict(int)
        for n in nums:
            m[n] += 1
            if (m[n] > len(nums) // 2):
                return n
        return 0

    def majorityElement_3(self, nums: List[int]) -> int:
        ans = 0
        for i in range(0, 32):
            hit = 0
            for n in nums:
                if n >> i & 1:
                    hit += 1
            if hit > len(nums) // 2:
                if i == 31: # if the 31th bit if 1, it means it's a negative number
                    ans = -((1 << 31) - ans)
                else:
                    ans += 1 << i
        
        return ans

    def majorityElement_4(self, nums: List[int]) -> int:
        candidate = 0
        count = 1
        for n in nums:
            if candidate != n:
                count -= 1
                if count == 0:
                    candidate = n
                    count = 1
            else:
                count += 1
                candidate = n
        return candidate

    def majorityElement(self, nums: List[int]) -> int:
        return self.majorityElement_4(nums)
        