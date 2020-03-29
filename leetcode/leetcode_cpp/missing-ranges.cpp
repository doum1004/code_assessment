#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/missing-ranges/

Solution1. two pointers
time: o(n)
space: o(1) ans(n)
    
*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        for (int i=0; i<=nums.size(); ++i) {
            long l = (i == 0) ? lower : (long)nums[i-1]+1;
            long r = (i == nums.size()) ? upper : (long)nums[i]-1;
            
            if (l<=r) {
                auto str = to_string(l);
                if (l < r) str += "->" + to_string(r);
                res.push_back(str);
            }
        }
        return res;
    }
};

int main()
{
    auto input1 = vector<int>{0, 1, 3, 50, 75};
    assert(Solution().findMissingRanges(input1, 0, 99) == (vector<string>{"2", "4->49", "51->74", "76->99"}));
    
    return 0;
}