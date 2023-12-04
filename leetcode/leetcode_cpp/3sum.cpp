#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/3sum

Solution1. Sliding window (two pointers)
time: o(n^2) nlogn + n^2(i*(l,r))
spcae: o(1) answer(n)

1. sort to avoid duplication
2. iterate nums and try to find target(-nums[i]) from two pointers in nums[l] and nums[r]. l++ r--
3. Add it in res if find, and try to move till non duplications (l,r)
4. move i to skip duplication

*/
class Solution {
public:
    vector<vector<int>> threeSum_1(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i=0; i<n-2; ++i) {
            int target = -nums[i];
            int l = i+1;
            int r = n-1;
            while (l<r) {
                int sum = nums[l] + nums[r];
                if (target < sum)
                    r--;
                else if (target > sum)
                    l++;
                else {
                    res.push_back({nums[i],nums[l],nums[r]});
                    int numL = nums[l];
                    int numR = nums[r];
                    while (l < r && nums[l] == numL) l++;
                    while (l < r && nums[r] == numR) r--;
                }
            }
            while (i < n - 1 && nums[i] == nums[i+1]) i++;
        }

        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSum_1(nums);
    }
};

int main()
{
    auto input1 = vector<int> {-1, 0, 1, 2, -1, -4};
    auto expect1 = vector<vector<int>>();
    expect1.push_back(vector<int> {-1, 0, 1});
    expect1.push_back(vector<int> {-1, -1, 2});
    assert(Solution().threeSum(input1)
        == expect1);
    return 0;
}