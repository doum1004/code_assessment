#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/move-zeroes/

// Solution1. iteration
// time: o(n)
// space: o(1)
iterate nums and erase and push back if num is 0

*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        auto n = nums.size();
        for (int i=0; i<n; ++i) {
            if (nums[i] == 0) {
                nums.push_back(0);
                nums.erase(nums.begin() + i);
                i--;
                n--;
            }
        }
    }
};

int main()
{
    auto input1 = vector<int> { 0, 1, 0, 3, 12 };
    auto expect1 = vector<int> { 0, 0, 1, 3, 12 };
    Solution().moveZeroes(input1);
    assert(input1 == expect1);

    return 0;
}