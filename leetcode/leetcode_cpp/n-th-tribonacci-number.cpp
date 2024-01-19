/*
https://leetcode.com/problems/n-th-tribonacci-number

1. Iteration
time: o(n)
space: o(1)
*/
class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        int a = 0, b = 1, c = 1;
        while (n - 2 > 0) {
            int d = a + b + c;
            a = b;
            b = c;
            c = d;
            n -= 1;
        }
        return c;
    }
};