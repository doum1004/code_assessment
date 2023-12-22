#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/trapping-rain-water

Solution1. Keep max l, r and get space
time: o(n)
space: o(n)

Solution2. Sliding window. Two pointers
time: o(n)
space: o(1)

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
*/

class Solution {
public:
    int trap_1(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        vector<int> l(n, height[0]);
        vector<int> r(n, height[n-1]);
        for (int i=1; i<n; ++i) {
            l[i] = max(l[i-1], height[i]);
        }
        for (int i=n-2; i>=0; --i) {
            r[i] = max(r[i+1], height[i]);
        }
        int res = 0;
        for (int i=1; i<n-1; ++i) {
            auto source = min(l[i], r[i]);
            if (source > height[i])
                res += source - height[i];
        }
        return res;
    }
    int trap_2(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int maxL=0, maxR = 0;
        int res = 0;
        while (l<r) {
            int curL = height[l];
            int curR = height[r];
            maxL = max(maxL, curL);
            maxR = max(maxR, curR);

            int cur = 0;
            if (curL < curR) {
                cur = curL;
                l++;
            }
            else {
                cur = curR;
                r--;
            }

            int ref = min(maxL, maxR);
            if (ref > cur) res += ref - cur;
        }
        return res;
    }
    int trap(vector<int>& height) {
        return trap_2(height);
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
