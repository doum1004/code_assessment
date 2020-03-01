#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

// https://leetcode.com/problems/trapping-rain-water/

// Soultion1. Two points. sliding window
// time: o(n)
// space: o(1)

// leftMax, rightMax
// 0 1 0 2 1 0 1
// l           r    water = 0  lhMax = 0, rhMax = 1
//   l         r    water = 0  lhMax = 1, rhMax = 1
//   l       r      water = 1 (min(lhMax, rhMax) - curh)
//   l     r        water = 1
//   l   r                                rhMax = 2
//     l            water = 2

// Solution 2. Stack
// time: o(n)
// space: o(n)
// 0 1 0 2 1 0 1 2
// l                                                                        stack(0) -> 0 index
//   l              remove(0)                                               stack(1) 
//     l                                                                    stack(1,2)
//       l          pop stack (2) -> water dist*(min(top,cur)-h[2])         stack(3)            water = 1
//           l                                                              stack(3, 4, 5)
//             l    pop stack (5) -> water dist*(min(top,cur)-h[5])         stack(3, 4 6)       water = 2
//               l  pop stack (6 4) -> water dist*(min(top,cur)-h[5])       stack(7)            water = 5           

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int l = 0, r = height.size() - 1;
        int lhMax = height[l], rhMax = height[r];
        
        int ans = 0;
        while (l<r) {
            auto h = 0;
            
            if (height[l] < height[r]) {
                lhMax = max(height[++l], lhMax);
                h = height[l];
            }
            else {
                rhMax = max(height[--r], rhMax);
                h = height[r];
            }
            auto h2 = min(lhMax, rhMax);
            if (h2 > h) {
                ans += h2 - h;
            }
        }
        
        return ans;
    }
};

int main()
{
    auto input1 = vector<int> {0,1,0,2,1,0,1,3,2,1,2,1};
    assert(Solution().trap(input1)
        == 6);
    auto input2 = vector<int> {0,1,0,2,1,0,1,3,2,1,2,1,4};
    assert(Solution().trap(input2)
        == 11);
    auto input3 = vector<int> {4,2,3};
    assert(Solution().trap(input3)
        == 1);
    return 0;
}