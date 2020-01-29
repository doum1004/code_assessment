#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>

using namespace std;

/**
// https://leetcode.com/problems/house-robber/

1 2 3 1
max: 1 3

1 2 3 1 1 5
max: 1 3 5

// iteration with dp
// time: o(n)
// space: o(1)
pre: 2 index before maxsum
cur: just before maxsum
cur = max(pre+n, cur) take one between just before or 2 index before + n

iteration n
    temp = cur
    cur = max(cur, pre + n)
    pre = temp
    
        1   2   3   1   1   5
tmp     0   1   2   4   4   5
cur     1   2   4   4   5   9 (ans)
pre     0   1   2   4   4   5

// recursion
// time: o(n^2)
// space: o(n^2)
r (nums, sum, i, &ans)
    if (nums.size() <= i) return;
    sum = sum + nums[i]
    ans = max(sum, anx)
    r(nums, sum, i + 2)
    r(nums, sum, i + 3)
ans
r(nums, ans)

*/

class Solution {
public:
    void rob_recursion(vector<int>& nums, int sum, int i, int& maxSum) {
        if (nums.size() <= i) return;
        sum += nums[i];
        maxSum = max(maxSum, sum);
        rob_recursion(nums, sum, i + 2, maxSum);
        rob_recursion(nums, sum, i + 3, maxSum);
    }
    
    int rob_recursion(vector<int>& nums) {
        int maxSum = 0;
        rob_recursion(nums, 0, 0, maxSum);
        rob_recursion(nums, 0, 1, maxSum);
        return maxSum;
    }
    
    int rob_iteration(vector<int>& nums) {
        auto pre = 0;
        auto cur = 0;
        for (auto &n : nums) {
            auto t = cur;
            cur = max(cur, pre + n);
            pre = t;
        }
        return cur;
    }
    
    int rob(vector<int>& nums) {
        //return rob_recursion(nums);
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