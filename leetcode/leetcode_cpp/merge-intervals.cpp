#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

/*
https://leetcode.com/problems/merge-intervals

Solution1. two pointers

// sort
// iterate and merge if needed, if not push to ans

[[1,3],[2,6],[8,10],[15,18]]
  l r

if ((i >= l && i <= r) || (j >= l && j <= r))
  // merge
  [min() max()]
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        // sort(intervals.begin(), intervals.end());
        sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b){ // same as default lambda
           return a[0] < b[0]; 
        });

        vector<vector<int>> res;
        for (auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0])
                res.push_back(interval);
            else
                res.back()[1] = max(res.back()[1], interval[1]);
        }
        return res;
    }
};

int main()
{
    auto input1_1 = vector<vector<int>> {{1,3},{2,6},{8,10},{15,18}};
    assert(Solution().merge(
        input1_1
    ) == (vector<vector<int>> {{1,6},{8,10},{15,18}}));
    return 0;
}