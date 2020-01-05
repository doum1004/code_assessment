#include <iostream>
#include <cassert>
#include "../../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

int trapRainWater(vector<int> height) {
    int l = 0, r = height.size() - 1;
    int ans = 0, l_m = 0, r_m = 0;
    while (l < r)
    {
        if (height[l] < height[r])
        {
            if (height[l] > l_m)
            {
                l_m = height[l];
            }
            else
            {
                ans += l_m - height[l];
            }
            l++;
        }
        else
        {
            if (height[r] > r_m)
            {
                r_m = height[r];
            }
            else
            {
                ans += r_m - height[r];
            }
            r--;
        }
    }
    return ans;
}

int trapRainWater_stack(vector<int> height) {
    stack<int> st;
    int ans = 0, cur = 0;
    while (cur < height.size()) {
        while (!st.empty() && height[cur] > height[st.top()]) {
            auto top = st.top();
            st.pop();
            if (st.empty())
                break;

            auto dis = cur - st.top() - 1;
            auto bounded_h = min(height[cur], height[st.top()]) - height[top];
            ans += dis * bounded_h;
        }
        st.push(cur++);
    }

    return ans;
}

int main()
{
    assert(trapRainWater(
        vector<int> {0,1,0,2,1,0,1,3,2,1,2,1})
        == 6);
    assert(trapRainWater(
        vector<int> {0,1,0,2,1,0,1,3,2,1,2,1,4})
        == 11);
    assert(trapRainWater(
        vector<int> {4,2,3})
        == 1);
    return 0;
}