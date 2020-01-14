#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        // two-points sliding window
        // time: o(n)
        // space: o(1)

        int ans = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            ans = max(ans, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return ans;
    }
};

int main()
{
    auto input1 = vector<int>{1,8,6,2,5,4,8,3,7};
    auto input2 = vector<int>{1,2,4,3};
    assert(Solution().maxArea(input1) == 49);
    assert(Solution().maxArea(input2) == 4);
    return 0;
}