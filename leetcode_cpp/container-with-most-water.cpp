#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/container-with-most-water/

// 1 8 6 2 5 4 8 3 7
// [1,8] 1*(1-0) = 1
// [8, 7] 7(min(8,7))*7(8-1)
// keep biger height and moves and store max

// sliding windows
// time: o(n)
// space: o(1)
// 1 8 6 2
// l     r  maxArea = 3
//   l   r  maxArea = 4
//   l r    maxArea = 6

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;
        
        int maxArea = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            auto h1 = height[l];
            auto h2 = height[r];
            maxArea = max(maxArea, (r-l) * min(h1, h2));
            if (h1 > h2) {
                r--;
            }
            else {
                l++;
            }
        }
        return maxArea;
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