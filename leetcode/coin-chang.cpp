#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

/**
https://leetcode.com/problems/coin-change/

// solution1. brute force sort coins and remove from largest till the last. if not move to next and try
// time: o(n^2)
// space: o(1)

// solution2. dp (1/0 Kanpsack)
// time: o(s*n) : s(amount) n(coins)
// space: o(s) : s(amount)
*/

class Solution {
public:
    int coinChange_bruteforce(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int start = coins.size()-1;
        
        while (start >= 0) {
            auto cur_amount = amount;
            auto count = 0;
            for (int i=start; i>=0; --i) {
                while (coins[i] <= cur_amount) {
                    cur_amount -= coins[i];
                    count++;
                }
                if (cur_amount == 0) return count;
            }
        }
        
        return -1;
    }
    
    int coinChange_dp(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i=1; i<=amount; ++i) {
            for (auto &coin:coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        //return coinChange_bruteforce(coins, amount);
        return coinChange_dp(coins, amount);
    }
};

int main()
{
    auto input1 = vector<int> {1,2,5};
    assert(Solution().coinChange(input1, 11)
        == 3);

    auto input2 = vector<int> {2};
    assert(Solution().coinChange(input2, 3)
        == -1);
    return 0;
}