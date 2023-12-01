#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

Solution1. Iterate
time: o(n)
space: o(1)

Solution2. Binary search
time: o(logn)
space: o(1)


Solution3. lower bound / uppder bound (stl)
time: o(logn)
space: o(1)

Solution4. custom lower/upper bound
time: o(logn)
space: o(1)

*/
class Solution {
public:
    vector<int> searchRange_1(vector<int>& nums, int target) {
        if (nums.size() < 1) return {-1, -1};

        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == target) {
                int j = i;
                while (j + 1 < nums.size() && nums[j+1] == target) j += 1;
                return {i, j};
            }                
        }

        return {-1, -1};
    }

    vector<int> searchRange_2(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l<=r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                int i = m;
                int j = m;
                while (i - 1 >= 0 && nums[i-1] == target) i -= 1;
                while (j + 1 < nums.size() && nums[j+1] == target) j += 1;
                return {i, j};
            }

            if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }

        return {-1, -1};
    }

    vector<int> searchRange_3(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        if (l == nums.end() || nums[int(l-nums.begin())] != target)
            return {-1, -1};
        return {int(l-nums.begin()), int(r-nums.begin()-1)};
    }

    int my_lower_bound(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int l = 0, r = nums.size()-1;
        while (l<r) {
            int m = (r-l)/2+l;
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        if (nums[l] == target) return l;
        return -1;
    }

    int my_upper_bound(vector<int>& nums, int target) {
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

    vector<int> searchRange_4(vector<int>& nums, int target) {
        auto l = my_lower_bound(nums, target);
        auto r = my_upper_bound(nums, target);
        if (l == -1 || nums[l] != target)
            return {-1, -1};
        return {l, r};
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return searchRange_4(nums, target);
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