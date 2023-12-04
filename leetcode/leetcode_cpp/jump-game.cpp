#include <iostream>
#include <cassert>

#include <vector>
#include <queue>

using namespace std;

/**
https://leetcode.com/problems/jump-game

- Solution1: backtracking
- time: o(2^n)
- space: o(n)

- Solution2: backtracking(top down) with dp
- time: o(n^2)
- space: o(2n) recursion + table

- soluiton3: dp(bottom up)
- time: o(n^2)
- space: o(n)

- solution4: greedy
- time: o(n)
- space: o(1)

*/

class Solution {
public:
    bool dfs(vector<int>& nums, int cur, unordered_map<int,bool>& dp) {
        if (cur == nums.size()-1) return true;
        if (dp.count(cur)) return dp[cur];
        
        bool res = false;
        for (int i=1; i<=nums[cur]; ++i) {
            res = dfs(nums, cur+i, dp);
            if (res)
                break;
        }
        dp[cur] = res;
        return res;
    }
    bool canJump_2(vector<int>& nums) {
        unordered_map<int,bool> dp;
        return dfs(nums, 0, dp);
    }

    bool canJump_3(vector<int>& nums) {
        int n = nums.size();
        if (n<1) return false;
        
        vector<int> t(n, 0);
        t[n-1] = 1;
        
        for (int i=n-2; i>=0; --i) {
            int p = i + nums[i];
            for (int j=i+1; j<=p; ++j) {
                if (j >= n-1 || t[j] == 1) {
                    t[i] = 1;
                    break;
                }
            }
            if (nums[0] >= i && t[i]) return true;
        }
        return t[0] == 1;
    }
    
    bool canJump_4(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return false;
        int m = nums[0];
        for (int i=0; i<=m; ++i) {
            if (m >= i) m = max(m, i+nums[i]);
            if (m >= n-1) return true;
        }
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        //return canJump_dp(nums);
        return canJump_4(nums);
    }
};

int main()
{
    auto input1 = vector<int> {2,3,1,1,4};
    assert(Solution().canJump(input1) == (true));
    
    auto input2 = vector<int> {3,2,1,0,4};
    assert(Solution().canJump(input2) == (false));
    
    return 0;
}