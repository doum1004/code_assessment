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

1 (1)
- 1

2 (2)
- 1 1
- 2

3 (3)
- 1 1 1
- 1 2
- 2 1

4 (5)
- 1 1 1 1
- 1 1 2
- 1 2 1
- 2 1 1
- 2 2

// solution1. Recusion with dp
// time: o(n)
// space: o(n) depth of recursion. dp make reducing the size of recursion
unordered_map<int, int> dp;
r(n)
    if n <= 2 return n
    if dp.find(n) return dp[n]
    auto l = r(n-1)
    auto r = r(n-2)
    dp[n] = l+r
    return dp[n]
    
// solution2. Iterative with dp
// time: o(n)
// space: o(n) size of map

// solution3. Fibonacci number
// time: o(n)
// space: o(1)

*/

class Solution {
public:
    unordered_map<int, int> dp;
    int climbStairs_recursion(int n) {
        if (n <= 2) return n;
        if (dp.find(n) != dp.end()) return dp[n];
        
        auto n1 = climbStairs_recursion(n-1);
        auto n2 = climbStairs_recursion(n-2);
        dp[n] = n1 + n2;
        return dp[n];
    }
    
    int climbStairs_iteration(int n) {
        if (n < 3) return n;
        unordered_map<int, int> m;
        m[1] = 1;
        m[2] = 2;
        for (int i=3; i<=n; i++) {
            m[i] = m[i-1] + m[i-2];
        }
        return m[n];
    }
    
    int climbStairs_fibonacci(int n) {
        if (n < 3) return n;
        
        int first = 1;
        int second = 2;
        for (int i=3; i<=n; ++i) {
            int third = first + second;
            first = second;
            second = third;
        }
        
        return second;
    }
    
    int climbStairs(int n) {
        //return climbStairs_recursion(n);
        //return climbStairs_iteration(n);
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