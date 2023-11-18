#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/climbing-stairs/

Solution0. Recursion
time: o(2^n)

solution1. dp(memorization) in recursion
time: o(n)
space: o(n). dp(n) + recursion(n)

solution2. dp(memorization) in iteration
time: o(n)
space: o(n). dp(n)

solution3. fibonacci number
time: o(n)
space: o(1)

1: 1 (1)
2: 2 (11,2)
3: 3 (111,12,21)
4: 5 (1111,121,211,112,22)

*/

class Solution {
public:
    int climbStaris_recursion(int n) {
       if (n == 0 || n == 1) return 1;       
       return  climbStaris_recursion(n - 1) + climbStaris_recursion(n - 2);
    }
    
    vector<int> dp_;
    int recursion(int n) {
        if (n <= 2) return n;
        if (dp_[n] != 0) return dp_[n];
        dp_[n] = recursion(n-1) + recursion(n-2);
        return dp_[n];
    }
    
    int climbStairs_dp_recursion(int n) {
        dp_ = vector<int>(n+1, 0);
        return recursion(n);
    }
    
    int climbStairs_dp_iteartion(int n) {
        if (n <= 2) return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp.back();
    }
    
    int climbStairs_fibonacci(int n) {
        if (n <= 2) return n;
        int pre2 = 1;
        int pre1 = 2;
        int cur = 0;
        for (int i=3; i<=n; ++i) {
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        
        return cur;
    }
    
    int climbStairs(int n) {
        //return climbStairs_dp_recursion(n);
        //return climbStairs_dp_iteartion(n);
        return climbStairs_fibonacci(n);
    }
};

int main()
{
    assert(Solution().climbStairs(2)
        == 2);
    assert(Solution().climbStairs(3)
        == 3);
    assert(Solution().climbStairs(4)
        == 5);
    return 0;
}