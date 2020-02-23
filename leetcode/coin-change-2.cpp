#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

/**
https://leetcode.com/problems/coin-change-2/

// Solution1. DP
https://www.youtube.com/watch?v=_fgjrs570YE
// time: o(C*A). C(coins). A(amounts)
// space: o(A). dp(vector for amounts)

1. create dp table (it can be one vector since it uses previous)
2. calculate new dp with coin

ex) coin (1,2,3) target (5)
  0 1 2 3 4 5
0 1 0 0 0 0 0
1 1 1 1 1 1 1 (1,1,1,1,1)
2 1 1 2 2 3 3 (2,1,1,1) (2,2,1)
3 1 1 2 3 4 5 (3,2) (3,1,1)

*/

class Solution {
public:
    int change_dp(int amount, vector<int>& coins) {
        // create dp table or vector
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (auto &coin:coins) {
            for (int i=1; i<=amount; ++i) {
                if (i - coin >= 0) dp[i] += dp[i - coin];    
            }
        }
        
        return dp[amount];
    }
    
    int change(int amount, vector<int>& coins) {
        return change_dp(amount, coins);
    }
};

int main()
{
    auto input1 = vector<int> {1,2,5};
    assert(Solution().change(5, input1) == 4);

    auto input2 = vector<int> {2};
    assert(Solution().change(3, input2) == 0);

    auto input3 = vector<int> {10};
    assert(Solution().change(10, input3) == 1);

    return 0;
}