#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

/*
https://leetcode.com/problems/maximum-subarray

Solution1. DP
time: o(n)
space: o(n)

Solution2. dp in space
time: o(n)
space: o(1)

Solution3. dp in space. no extra value
time: o(n)
space: o(1)

// sliding window
// time: o(n)
// maxs = num[0]
// curs = num[0]
// -2 1 -3 4 -1 2 1 -5 4
// loop ...                 curs = max(num[i], curs + num[i]) maxs = max(curs, maxs)
//    i                     curs = max(1, -2+1=-1)  maxs = max(-2, 1) = 1
//       i                  curs = max(-3, 1-3 = -2)    maxs = (1,-2) = 1
//         i                curs = max(4, -2+4=2) = 4   maxs = (1, 4) = 4

Solution4. divide and conquer (find the max sum of each and merge)
time: o(n)
space: o(n)
*/

class Solution {
public:
    int maxSubArray_1(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];

        int maxSum = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
    int maxSubArray_2(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int maxSum = nums[0];
        int sum = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
    int maxSubArray_3(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int maxSum = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            nums[i] = max(nums[i], nums[i-1] + nums[i]);
            maxSum = max(maxSum, nums[i]);
        }
        return maxSum;
    }
    int maxSubArray_4(vector<int>& nums, int l, int r) {
        if (l > r) return INT_MIN;
        int m = l + (r - l) / 2;
        int lmax = maxSubArray_4(nums, l, m - 1);
        int rmax = maxSubArray_4(nums, m, r);

        int lsum = 0;
        int rsum = 0;
        for (int i=m-1, sum=0; i>=l; i++) {
            sum += nums[i];
            lsum = max(lsum, sum);
        }
        for (int i=m+1, sum=0; i <= r; ++i) {
            sum += nums[i];
            rsum = max(rsum, sum);
        }
        return max(max(lmax, rmax), lsum + nums[m] + rsum);
    }
    int maxSubArray_4(vector<int>& nums) {
        return maxSubArray_4(nums, 0, nums.size()-1);
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArray_3(nums);
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