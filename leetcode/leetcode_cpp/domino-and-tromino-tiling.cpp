/*
https://leetcode.com/problems/domino-and-tromino-tiling

1. dp
time: o(n)
space: o(n)
*/
class Solution {
public:
#define md 1000000007
    int numTilings(int n) {
        if (n <= 2) return n;
        if (n == 3) return 5;
        vector<long long> v(n+1, 0);
        v[1] = 1;
        v[2] = 2;
        v[3] = 5;
        for (int i=4; i<=n; ++i) v[i] = (2*v[i-1] + v[i-3]) % md;
        return v[n];
    }
};