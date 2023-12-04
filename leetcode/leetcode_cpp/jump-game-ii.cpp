/*
https://leetcode.com/problems/jump-game-ii

Solution1. Bottom Up Tabulation.
time: o(n^2)
space: o(n)

     2   3  1   1   4
dp=[-1][-1][-1][-1][0]

Solution2. Linear. Greedy
time: o(n)
space: o(1)
*/
class Solution {
public:
    int jump_1(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 0;
        for (int i=n-2; i>=0; --i) {
            if (nums[i] == 0) continue;
            
            int reach = min(i+nums[i], n-1);
            for (int j=i+1; j<=reach; ++j) {
                if (dp[j] == -1) continue;
                if (dp[i] == -1)
                    dp[i] = 1+dp[j];
                else
                    dp[i] = min(dp[i], 1+dp[j]);
            }
        }
        return dp[0];
    }

    int jump_2(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return -1;

        int jump = 0;
        int maxReach = 0;
        int reach = 0;
        for (int i=0; i<n-1; ++i) {
            maxReach = max(maxReach, i + nums[i]);
            if (i==reach) {
                jump += 1;
                reach = maxReach;
            }
        }
        return jump;
    }

    int jump(vector<int>& nums) {
        return jump_2(nums);
    }
};