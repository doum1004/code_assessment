#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray_greedy_dp(vector<int>& nums) {
        if (nums.size() < 2) return (nums.size() == 0) ? 0 : nums[0];

        auto maxSum = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i - 1] > 0) nums[i] += nums[i - 1];
            maxSum = max(maxSum, nums[i]);
        }

        return maxSum;
    }

    int maxSubArray_greedy(vector<int>& nums) {
        if (nums.size() < 2) return nums.size() == 0 ? 0 : nums[0];
        
        auto maxSum = nums[0], curSum = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            curSum = max(nums[i], curSum + nums[i]);
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArray_greedy_dp(nums);
        //return maxSubArray_greedy(nums);
    }
};

int main()
{
    auto input1_1 = vector<int> {-2,1,-3,4,-1,2,1,-5,4};
    assert(Solution().maxSubArray(
        input1_1
    ) == (6));
    auto input2_1 = vector<int> {-2,-1};
    assert(Solution().maxSubArray(
        input2_1
    ) == (-1));
    return 0;
}