#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>

using namespace std;
/*
https://leetcode.com/problems/house-robber

Solution1. DP top down Recursion with Memorization in place
time: o(n)
space: o(n) recursion + hashmap (memorization)

Solution2. DP bottom down with Tabulation (in place)
time: o(n)
space: o(1)

*/

class Solution {
public:
    int recurse(vector<int>& nums, int i, unordered_map<int, int>& hm) {
        if (i >= nums.size()) return 0;
        if (hm.count(i)) return hm[i];
        int v = nums[i];
        int v1 = recurse(nums, i+2, hm);
        int v2 = recurse(nums, i+3, hm);
        hm[i] = v + max(v1, v2);
        return hm[i];
    }

    int rob_1(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        unordered_map<int, int> hm;
        recurse(nums, 0, hm);
        recurse(nums, 1, hm);
        return max(hm[0], hm[1]);
    }

    int rob_2(vector<int>& nums) {
        int n1 = nums.size();
        if (n1 == 0) return 0;
        if (n1 == 1) return nums[0];
        for (int i = n1-3; i>=0; --i) {
            if (i == n1-3)
                nums[i] += nums[i+2];
            else
                nums[i] += max(nums[i+2], nums[i+3]);
        }

        return max(nums[0], nums[1]);
    }

    int rob(vector<int>& nums) {
        return rob_2(nums);
    }
};

int main()
{
    auto input1 = vector<int> {1,2,3,1};
    assert(Solution().rob(input1) == 4);
    auto input2 = vector<int> {2,7,9,3,1};
    assert(Solution().rob(input1) == 12);
   
    return 0;
}