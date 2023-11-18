/*
https://leetcode.com/problems/sqrtx

Solution1. Iternation
time: o(n)
space: o(1)

Solution2. binary search
time: o(logn)
space: o(1)

*/
class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;
        while (l<=r) {
            int m = l + (r - l) / 2; // avoid over flow
            if (x / m == m) return m;
            if (x / m < m) r = m - 1;
            else l = m + 1;
        }
        return r;
    }
};