/*
https://leetcode.com/problems/number-of-1-bits

solution1. bit manipulation
time: o(logn)
space: o(1)

solution2. bit manipulation (popcount). erase lesat 1 each time
time: o(logn)
space: o(1)

ex) 001101
count(1) 001101 & 001100 = 001100
count(2) 001100 & 001011 = 001000
count(3) 001000 & 000111 = 000000

*/
class Solution {
public:
    int hammingWeight_1(uint32_t n) {
        int c = 0;
        while (n > 0) {
            if (n & 1 != 0)
                c++;
            n >>= 1;
        }
        return c;        
    }
    
    int hammingWeight_2(uint32_t n) {
        int c = 0;
        while (n > 0) {
            n = n & n - 1;
            c++;
        }
        return c;
    }

    int hammingWeight(uint32_t n) {
        return hammingWeight_2(n);
    }
};