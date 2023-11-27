'''
https://leetcode.com/problems/maximum-sum-circular-subarray

maximum sum is either max (we get using kadane's algo) or (sum - min).
There is a special case, if sum == min,
then maximum sum is max.

Let's develop an algorithm to solve this problem.
1. Find maximum subarray sum using kadane's algorithm (max) 
2. Find minimum subarray sum using kadane's algorithm (min)
3. Find total sum of the array (sum)
4. Now, if sum == min return max
5. Otherwise, return maximum ( max, sum - min )

IF YOU HAVE ANY DOUBTS, FEEL FREE TO ASK
IF YOU UNDERSTAND, DON'T FORGET TO UPVOTE.

IF YOU WANT MORE ANSWERS, PLEASE FOLLOW ME.

Time :- O(N)
Space :- O(1)
'''
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return nums[0]

        sum = nums[0]
        max_sum = nums[0]
        max_cur = nums[0]
        min_sum = nums[0]
        min_cur = nums[0]

        for i in range(1, n):
            num = nums[i]
            sum += num

            max_cur = max(num, max_cur + num)
            max_sum = max(max_sum, max_cur)
            
            min_cur = min(num, min_cur + num)
            min_sum = min(min_sum, min_cur)
        
        if sum == min_sum:
            return max_sum
        
        return max(max_sum, sum - min_sum)
        
        