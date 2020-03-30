#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Solution1. builtin lower_bound upper_bound
// time: o(logn) lower_bound(logn) upper_bound(logn)
// space: o(1)

// Solution2. custom lower_bound and upper_bound
// time: o(logn)
// space: o(1)

*/

class Solution {
public:
    vector<int> searchRange_builtin(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        if (l != nums.end() && nums[l-nums.begin()] == target) return {int(l-nums.begin()), int(r-nums.begin()-1)};
        return {-1, -1};
    }
    
    int custom_lower_bound_1(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while (l<=r) {
            int m = (r-l)/2+l;
            if (nums[m] < target) l=m+1;
            else r=m-1;
        }
        return l;
    }
    
    int custom_lower_bound(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int l=0, r=nums.size()-1;
        while (l<r) {
            int m = (r-l)/2+l;
            if (nums[m] < target) l = m+1;
            else r = m;
        }
        if (nums[l] == target) return l;
        return -1;
    }
    
    int custom_upper_bound(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int l=0,r=nums.size()-1;
        while (l<r) {
            int m=(r-l+1)/2+l;
            if (nums[m] <= target) l = m;
            else r = m-1;
        }
        if (nums[r] == target) return r;
        return -1;
    }
    
    vector<int> searchRange_custom(vector<int>& nums, int target) {
        auto l = custom_lower_bound(nums, target);
        auto r = custom_upper_bound(nums, target);
        if (l < nums.size() && nums[l] == target) return {l,r};
        return {-1,-1};
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        //return searchRange_builtin(nums, target);
        return searchRange_custom(nums, target);
    }
};

int main()
{
    auto input1 = vector<int>{5,7,7,8,8,10};
    assert(Solution().searchRange(input1, 8) == (vector<int> {3,4}));

    auto input2 = vector<int>{5,7,7,8,8,10};
    assert(Solution().searchRange(input2, 6) == (vector<int> {-1,-1}));

    return 0;
}