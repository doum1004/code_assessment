/*
https://leetcode.com/problems/insert-interval

Solution. Add and iterate to merge
time: o(n)
space: o(n)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (!intervals.size()) return {newInterval};
        int n = intervals.size();
        for (int i=0; i<n; ++i) {
            auto& interval = intervals[i];
            if (interval[0] > newInterval[0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }
        if (n == intervals.size())
            intervals.push_back(newInterval);

        vector<vector<int>> res;
        for (int i=0; i<intervals.size(); ++i) {
            auto& interval = intervals[i];
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            }
            else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};