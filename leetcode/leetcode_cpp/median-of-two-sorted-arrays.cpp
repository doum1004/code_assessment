#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/median-of-two-sorted-arrays/
// https://www.youtube.com/watch?v=LPFhl65R7ww

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (true) {
            // log(m+n) / o(1) use binsearch to find median in two sorted arrays
            int n1 = nums1.size();
            int n2 = nums2.size();
            if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
            
            int l = 0, r = n1;
            while (l<=r) {
                auto px = (l+r) / 2;
                auto py = (n1+n2+1) / 2 - px;
                
                auto x1 = (px == 0) ? INT_MIN : nums1[px-1];
                auto x2 = (px == n1) ? INT_MAX : nums1[px];
                
                auto y1 = (py == 0) ? INT_MIN : nums2[py-1];
                auto y2 = (py == n2) ? INT_MAX : nums2[py];
                
                if (x1 <= y2 && y1 <= x2) {
                    if ((n1 + n2) % 2 == 1) return max(x1,y1);
                    else return (max(x1,y1) + min(x2,y2)) / 2.0;
                }
                else if (x1 < y2) {
                    l = px + 1;
                }
                else {
                    r = px - 1;
                }
            }
            return -1;
        }
        else {
            // merge and sort in new place and return median
            // o(n+m) / o(n+m)
            int n1 = nums1.size(), n2 = nums2.size();
            
            vector<int> ans;
            int l=0, r=0;
            while (l<n1 && r<n2) {
                if (nums1[l] < nums2[r]) {
                    ans.push_back(nums1[l++]);
                }
                else {
                    ans.push_back(nums2[r++]);
                }
            }
            while (l < n1) ans.push_back(nums1[l++]);
            while (r < n2) ans.push_back(nums2[r++]);
            
            auto m = ans.size() / 2;
            if (ans.size() % 2 == 1) return ans[m];
            else return (ans[m-1] + ans[m]) / 2.0;
        }
    }
};

int main()
{
    auto input1_1 = vector<int> {1, 3};
    auto input1_2 = vector<int> {2};
    assert(Solution().findMedianSortedArrays(
        input1_1, input1_2
    ) == 2.0);
    auto input2_1 = vector<int> {1, 2};
    auto input2_2 = vector<int> {3, 4};
    assert(Solution().findMedianSortedArrays(
        input2_1, input2_2
    ) == 2.5);
    auto input3_1 = vector<int> {0, 0};
    auto input3_2 = vector<int> {0, 0};
    assert(Solution().findMedianSortedArrays(
        input3_1, input3_2
    ) == 0);
    return 0;
}
