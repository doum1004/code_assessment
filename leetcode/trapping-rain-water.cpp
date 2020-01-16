#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

// sliding window approch
// l, r points
// 0 1 0 2 1 0 1 3 2 1 2 1
//             l r      
//       lm      rm
// ans += 1
// ans += 1
// ans += 1
// ans += 2
// ans ++ 1
// time o(n)
// space o(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lm_h = 0, rm_h = 0;
        int ans = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] > lm_h) {
                    lm_h = height[l];
                }
                else {
                    ans += lm_h - height[l];
                }
                l++;
            }
            else
            {
                if (height[r] > rm_h) {
                    rm_h = height[r];
                }
                else {
                    ans += rm_h - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};

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