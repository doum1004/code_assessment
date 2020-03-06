#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/container-with-most-water/submissions/

Solution1. Brute force...
time: o(n^2)
space: o(1)

Solution2. Sliding window
time: o(n)
space: o(1)

1. set l=0, r=size()-1
2. loop (l<r)
2.1 save container mount
2.2 if h[l] < l++ else r--

1 8 6 2
l     r  maxArea = 3
  l   r  maxArea = 4
  l r    maxArea = 6

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 1) return 0;
        
        int maxArea = 0;
        int l = 0, r = height.size()-1;
        while (l<r) {
            auto area = min(height[l], height[r]) * (r-l);
            
            maxArea = max(maxArea, area);
            if (height[l] < height[r]) l++;
            else r--;
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