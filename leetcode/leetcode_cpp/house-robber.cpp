#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>

using namespace std;

/**
https://leetcode.com/problems/house-robber/

// Solution1. Recursive (give index 2, 3 steps futher and sum of money)
// time o(2^n)
// space o(2^n)
ans = 0
recursive(nums, i, money)
    if (i >= nums.size()) {
       ans = max(ans, money) 
    }
    money += nums[i];
    recursive(nums, i+2, money)
    recursive(nums, i+3, money)

// Solution2. Iterative with dp (presum, cursum, ans)
// time o(n)
// space o(1)

     1 2 3 1
p 0
c 0
a    1

p 0
c 1
a      2

p 1
c 2
a        4

p 2
c 4
a         4

     2 6 9 3 1
p 0
c 0
a    2

p 0
c 2
a      6

p 2
c 6
a        11

p 6
c 11
a          11

p 11
c 11
a            12

*/

class Solution {
public:
    int rob_iteration(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        
        auto pre = 0, cur = 0;
        for (auto &n:nums) {
            auto t = cur;
            cur = max(pre + n, cur);
            pre = t;
        }
        return cur;
    }
    
    int rob(vector<int>& nums) {
        return rob_iteration(nums);
    }
};

int main()
{
    auto input1 = vector<int> {1,2,3,1};
    assert(Solution().rob(input1) == 4);
    auto input2 = vector<int> {2,7,9,3,1};
    assert(Solution().rob(input1) == 12);
   
    return 0;
}