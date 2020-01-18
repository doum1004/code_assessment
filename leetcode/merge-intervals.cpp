#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return intervals;

        // sort
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        // merge
        for (auto interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            }
            else {
                auto back = ans.back();
                ans.back()[1] = max(back[1], interval[1]);
            }
        }

        return ans;
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