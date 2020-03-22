#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/summary-ranges/

Solution1. two pointers
// time: o(n)
// space: o(1)

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() < 1) return {};
        
        vector<string> res;
        int l=0;
        for (int i=1; i<=nums.size(); ++i) {
            if (i == nums.size() || nums[i] != nums[i-1]+1) {
                string s = to_string(nums[l]);
                if (l != i-1) s += "->" + to_string(nums[i-1]);
                res.push_back(s);
                l = i;
            }
        }
        return res;
    }
};

int main()
{
    auto input1 = vector<int> {0,1,2,4,5,7};
    assert(Solution().summaryRanges(input1) == (vector<string> {"0->2","4->5","7"}));

    return 0;
}
