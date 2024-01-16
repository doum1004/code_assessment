/*
https://leetcode.com/problems/find-the-highest-altitude

1. Iterate and accumulate
time: o(n)
space: o(1)
*/
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int cur = 0;
        for (int i=0; i<gain.size(); ++i) {
            cur += gain[i];
            res = max(res, cur);
        }
        return res;
    }
};