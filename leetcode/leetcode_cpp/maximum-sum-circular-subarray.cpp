/*
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
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int total_sum = nums[0];
        int maxSum = nums[0];
        int curMax = nums[0];
        int minSum = nums[0];
        int curMin = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            auto num = nums[i];
            total_sum += num;

            curMax = max(num, curMax + num);
            maxSum = max(maxSum, curMax);

            curMin = min(num, curMin + num);
            minSum = min(minSum, curMin);
        }
        if (total_sum == minSum) return maxSum;

        return max(maxSum, total_sum - minSum);
    }
};