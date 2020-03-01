#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/number-of-1-bits/

// Solution1. bit manipulation. 32 bit iteration to count number 1
// time o(m) : 32bit
// space o(1)

// Solution2. bit manipulation (popcount). erase lesat 1 each time
ex) 001101
count(1) 001101 & 001100 = 001100
count(2) 001100 & 001011 = 001000
count(3) 001000 & 000111 = 000000

count
for (count=0; n!=0; count++)
    n &= n-1;
return count

*/

class Solution {
public:
    int hammingWeight_bit(uint32_t n) {
        int count = 0;
        for (int i=0; i<32; ++i) {
            count += n >> i & 1;
        }
        return count;
    }
    
    int hammingWeight_popcount(uint32_t n) {
        int count = 0;
        for (;n!=0;count++) {
            n &= n-1;
        }
        return count;
    }
    
    int hammingWeight(uint32_t n) {
        //return hammingWeight_bit(n);
        return hammingWeight_popcount(n);
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
