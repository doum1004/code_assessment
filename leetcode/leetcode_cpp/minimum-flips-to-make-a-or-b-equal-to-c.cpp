/*
https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

1. bit manipulation
time: o(n)
space: o(1)
*/
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while (a || b || c) {
            int bit_a = a & 1;
            int bit_b = b & 1;
            int bit_c = c & 1;

            if (bit_c == 0) res += bit_a + bit_b;
            else if (bit_a + bit_b == 0) res += 1;

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return res;
    }
};