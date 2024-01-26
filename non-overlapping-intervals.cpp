/*
https://leetcode.com/problems/non-overlapping-intervals
1. Sort and Iteration (greedy)
time: o(n)
space: o(1)
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (!intervals.size()) return 0;
        sort(begin(intervals), end(intervals), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int res = 0;
        auto& prev = intervals[0];
        for (int i=1; i<intervals.size(); ++i) {
            if (prev[1] > intervals[i][0]) res += 1;
            else prev = intervals[i];
        }
        return res;
    }
};