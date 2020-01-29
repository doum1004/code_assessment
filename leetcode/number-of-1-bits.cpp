#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/number-of-1-bits/

// Solution1. popcount
// time: o(n) : worst
// space: o(1)
use bit manipulation to make least significant 1-bit to 0 each step

*/

class Solution {
public:
    int popcount(uint32_t n) {
        int count;
        for (count=0; n!=0; count++) {
            n &= n-1;
        }
        return count;
    }
    
    int hammingWeight(uint32_t n) {
        return popcount(n);
    }
};

int main()
{
    assert(Solution().hammingWeight(00000000000000000000000000001011)
        == (3));
    assert(Solution().hammingWeight(00000000000000000000000010000000)
        == (1));

    return 0;
}
