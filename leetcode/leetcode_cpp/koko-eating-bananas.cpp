/*
https://leetcode.com/problems/koko-eating-bananas

1. brute force
time: o(m^n)
space: o(1)

2. binary search
time: o(logn)
space: o(1)

*/
class Solution {
public:
    int minEatingSpeed_1(vector<int>& piles, int h) {
        int res = 1;
        while (true) {
            int hour = 0;
            for (int i=0; i<piles.size(); ++i) {
                if (hour > h) break;                
                hour += piles[i] / res;
                if (piles[i] % res != 0) hour += 1;
            }
            if (hour <= h) break;
            res += 1;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MIN;
        for (int n:piles) r = max(r, n);
        while (l<=r) {
            int m = l + (r-l) / 2;
            int hour = 0;
            for (int i=0; i<piles.size(); ++i) {
                hour += piles[i] / m;
                if (piles[i] % m != 0) hour += 1;
                if (hour > h) break;                
            }
            if (hour <= h) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
};