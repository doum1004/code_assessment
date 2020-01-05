#include <iostream>
#include <vector>
#include <cassert>
#include "../../utils.h"

using namespace std;

int maxArea2(vector<int> height) {
    auto n = height.size();
    auto ans = 0;

    auto map = unordered_map<int, int>();
    for (int x = 0; x < n-1; x++)
    {
        auto y = height[x];
        for (int x2 = x + 1; x2 < n; x2++)
        {
            auto y2 = height[x2];
            ans = max(ans, abs(x2 - x) * min(y2, y));
        }
    }

    return ans;
}

int maxArea(vector<int> height) {
    auto n = height.size();
    int ans = 0, l = 0, r = n - 1;
    while (l < r) {
        ans = max(ans, (r - l) * min(height[r], height[l]));
        if (height[r] > height[l])
            l++;
        else
            r--;
    }

    return ans;
}

int main()
{
    assert(maxArea(vector<int>{1,8,6,2,5,4,8,3,7}) == 49);
    assert(maxArea(vector<int>{1,2,4,3}) == 49);
    return 0;
}