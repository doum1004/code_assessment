#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/maximum-subarray/

// sliding window
// time: o(n)
// maxs = num[0]
// curs = num[0]
// -2 1 -3 4 -1 2 1 -5 4
// loop ...                 curs = max(num[i], curs + num[i]) maxs = max(curs, maxs)
//    i                     curs = max(1, -2+1=-1)  maxs = max(-2, 1) = 1
//       i                  curs = max(-3, 1-3 = -2)    maxs = (1,-2) = 1
//         i                curs = max(4, -2+4=2) = 4   maxs = (1, 4) = 4
// ...

    

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int maxSum = nums[0];
        if (false) {
            int curSum = nums[0];
            for (int i=1; i<nums.size(); ++i) {
                curSum = max(nums[i], curSum + nums[i]);
                maxSum = max(curSum, maxSum);
            }   
        }
        else {
            // DP. set cursum on previous
            for (int i=1; i<nums.size(); ++i) {
                nums[i] = max(nums[i], nums[i-1] + nums[i]);
                maxSum = max(maxSum, nums[i]);
            }
        }
        
        return maxSum;
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