#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

/**
https://leetcode.com/problems/maximum-product-subarray/

solution1. brute force
time: o(n^2)
space: o(1)

solution2. dp
time: o(n)
space: o(1)

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return INT_MIN;
        
        int preA, preB, res;
        preA = preB = res = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            auto a = nums[i];
            auto b = a * preA;
            auto c = a * preB;
            preA = min(min(a,b),c);
            preB = max(max(a,b),c);
            
            res = max(res, max(preA, preB));
        }
        
//         preA = preB = res = nums[nums.size()-1];
//         for (int i=nums.size()-2; i>=0; --i) {
//             auto a = nums[i];
//             auto b = a * preA;
//             auto c = a * preB;
//             preA = min(min(a,b),c);
//             preB = max(max(a,b),c);
            
//             res = max(res, max(preA, preB));
//         }
        return res;
    }
};

int main()
{
    auto input1 = vector<int> {2,3,-2,4};
    assert(Solution().maxProduct(input1) == (6));

    auto input2 = vector<int> {-2,0,-1};
    assert(Solution().maxProduct(input2) == (6));

    return 0;
}
