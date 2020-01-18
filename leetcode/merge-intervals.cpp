#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/merge-intervals/

// sort and merge
// [1,3], [2,6], [8,10], [15,18]
// sort
// [1,3], [2,6], [8,10], [15,18]
// merge vector
// v [1, 3]
// v [1, 6]
// v [1, 6] [8, 10]
// v [1, 6] [8, 10] [15, 18]

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;
        
        // sort
        sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b){
           return a[0] < b[0]; 
        });
        
        // merge
        vector<vector<int>> ans;
        for (auto &interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            }
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
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