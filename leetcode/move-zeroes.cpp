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

// Soluiton1 iterate vector and erase and pushback
// time: o(n)
// space: o(1)

for (int i=0; i<nums.size(); ++i) {
    if (nums[i] == 0) {
        nums.erase(nums.begin() + i);
        nums.push_back(nums[i]);
        i--;
    }
}

// Soluiton2 iterate swap none zero nums on left
// time: o(n)
// space: o(1)

auto l=0;
for (auto &n:nums) { if (n !=0) swap(n, nums[l++])}
*/

class Solution {
public:
    void moveZeroes1(vector<int>& nums) {
        auto n = nums.size();
        for (int i=0; i<n; ++i) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                i--;
                n--;
            }
        }
    }
    
    void moveZeroes(vector<int>& nums) {
        auto l = 0;
        for (auto &n:nums) {
            if (n != 0) {
                swap(n, nums[l++]);
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