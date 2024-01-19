#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>

using namespace std;

/*
https://leetcode.com/problems/house-robber

Solution1. DP top down Recursion with Memorization in place
time: o(n)
space: o(n) recursion + hashmap (memorization)

Solution2. DP bottom down with Tabulation (in place)
time: o(n)
space: o(1)
*/
class Solution {
public:
    int dfs(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int l = dfs(nums, i+2, dp);
        int r = dfs(nums, i+3, dp);
        return dp[i] = nums[i] + max(l, r);
    }
    
    int rob_1(vector<int>& nums) {
        if (!nums.size()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), -1);
        dfs(nums, 0, dp);
        dfs(nums, 1, dp);
        return max(dp[0], dp[1]);
    }
    
    int rob_2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        for (int i=n-3; i>=0; --i) {
            if (i == n-3)            
                nums[i] = nums[i] + nums[i+2];
            else
                nums[i] = nums[i] + max(nums[i+2], nums[i+3]);
        }
        return max(nums[0], nums[1]);
    }

    int rob(vector<int>& nums) {
        return rob_2(nums);
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