#include <iostream>
#include <cassert>

#include <vector>
#include <queue>

using namespace std;

/**
https://leetcode.com/problems/jump-game/

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
    bool canJump_dp(vector<int>& nums) {
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
    
    bool canJump_linear(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return false;
        int m = nums[0];
        for (int i=0; i<=m; ++i) {
            m = max(m, i+nums[i]);
            if (m >= n-1) return true;
        }
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        //return canJump_dp(nums);
        return canJump_linear(nums);
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