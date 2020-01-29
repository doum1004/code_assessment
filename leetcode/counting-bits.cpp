#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/counting-bits/

0 -> 0
1 -> 1 (1)
2 -> 10 (1)
3 -> 11 (2)
4 -> 100 (1)
5 -> 101 (2)
6 -> 110 (2)
7 -> 111 (3)
8 -> 1000 (1)
9 -> 1001 (2)
10 -> 1010 (2)
11 -> 1011 (3)
12 -> 1100 (2)

// solution1. popcount
// time: o(n*k) k=number of bits in each n
// space: o(n): ans result

// Soution2. dp + least_significant_bit
// time: o(n): linear
// space: o(n): ans
count(x/2) + x mod 2
1010 10 => count(5) + 10 % 2
1011 11 => count(5) + 11 % 2
101 5 ()

// Solution3. dp + last set bit
p(x) = p(last set bit) + 1
last set bit = x &= x - 1
1010 -> 1000 + c(1)
1100 -> 1000 + c(1)
1011 -> 1010 + c(1)
1111 -> 1110 + c(1)

*/

class Solution {
public:
    int popcount(int x) {
        int count;
        for (count=0; x!=0; count++) {
            x &= x-1;
        }
        return count;
    }
    
    vector<int> countBits_popcount(int num) {
        vector<int> ans;
        for (int n=0; n<=num; ++n)
            ans.push_back(popcount(n));
        
        return ans;
    }
    
    vector<int> countBits_least_significant_bit(int num) {
        vector<int> ans(num+1, 0);
        for (int i=1; i<=num; ++i) {
            ans[i] = ans[i >> 1] + (i & 1); // x / 2 is x >> 1 and x % 2 is x & 1
        }
        return ans;
    }
    
    vector<int> countBits_last_set_bit(int num) {
        vector<int> ans(num + 1, 0);
        for (int i=1; i<=num; ++i) {
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
    
    vector<int> countBits(int num) {
        //return countBits_popcount(num);
        //return countBits_least_significant_bit(num);
        return countBits_last_set_bit(num);
    }
};

int main()
{
    auto expected1 = vector<int> {0, 1, 1};
    assert(Solution().countBits(2)
        == (expected1));
    auto expected2 = vector<int> {0, 1, 1, 2, 1, 2};
    assert(Solution().countBits(5)
        == (expected2));

    return 0;
}
