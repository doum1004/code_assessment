#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

/**
https://leetcode.com/problems/coin-change/

// Solution1. brute force in recursion.
// time: S^n. S: amount. n: number of coins
// space: o(n) : recursion number of coin
recursion(idx, coins, amount)
    if (amount == 0) return 0;
    if (idx < 0 || idx >= coins.size()) return -1;
    
    int maxval = amount/coins[idx];
    int minCost = INT_MAX;
    for (int x=0; x<=maxval; ++x)
        int res = recursion(idx+1, coins, amount - x * coins[idx]);
        if (res != -1)
            minCost = min(minCost, res+x);
    return (minCost == INT_MAX) ? -1 : minCost

// Soultion2. dp table
// https://www.youtube.com/watch?v=Y0ZqKpToTic
1. create a table (row:coin with 0, amount: col)
-> this can be one vector since it use previous row.
2. do calcuation dp. f(x) = min(f(x), f(x-coin) + 1)

ex) coin (2,3,4) target 7
    0 1 2 3 4 5 6 7
0   0 7 7 7 7 7 7 7
2   0 7 1 7 2 7 3 7
3   0 7 1 1 2 2 2 3
4   0 7 1 1 1 2 2 2

4(7) -> 4(4) 4
4(4) -> 3(4) 3
3(4) -> 3(0)

ex) coin (2,3) target 7
    0 1 2 3 4 5 6 7
0   0 8 8 8 8 8 8 8
2   0 8 1 8 2 8 3 8
3   0 8 1 1 2 2 2 3
3(7) -> 3(4) 3
3(4) -> 2(4) 2
2(4) -> 2(2) 2
2(2) -> 2(0)

ex) coin (2,4) target 7
    0 1 2 3 4 5 6 7
0   0 8 8 8 8 8 8 8
2   0 8 1 8 2 8 3 8
4   0 8 1 7 1 8 2 8
8 > 7 -> -1

*/

class Solution {
public:
    int coinChange_bruteforce_recursion(int idx, vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (idx < 0 || idx >= coins.size()) return -1;
        
        int maxval = amount/coins[idx];
        int minCost = INT_MAX;
        for (int x=0; x<=maxval; ++x) {
            int res = coinChange_bruteforce_recursion(idx+1, coins, amount - x * coins[idx]);
            if (res != -1)
                minCost = min(minCost, res+x);
        }
        return (minCost == INT_MAX) ? -1 : minCost;
    }
    
    int coinChange_dp(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for (auto &coin:coins) {
            for (int i=1; i<=amount; i++) {
                if (i >= coin) dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        //return coinChange_bruteforce_recursion(coins, amount);
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