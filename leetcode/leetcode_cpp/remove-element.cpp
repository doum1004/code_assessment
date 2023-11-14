#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

/**
https://leetcode.com/problems/remove-element/

sol1. two pointers
time: o(n)
space: o(1)

*/

class Solution {
public:
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            auto& num = nums[j++];
            if (num != val) {
                nums[i++] = num;
            }
        }
        return i;
    }
};

int main()
{
    auto input1 = vector<int> {3,2,2,3};
    auto result = Solution().removeElement(input1, 3);
    auto expect = vector<int> {2,2,2,3};
    assert(result == 2);
    assert(input1 == expect);
    return 0;
}