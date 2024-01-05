#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

/*
https://leetcode.com/problems/median-of-two-sorted-arrays

Solution1. Sort
time: o(nlogm)
space: o(n)

Solution2. Two Pointers
time: o(n)
space: o(n)

1 2 3 4 % 2 = 00
-> (2 + 3) / 2
1 2 3
-> 2

Solution3. Binary search (TODO)
https://www.youtube.com/watch?v=LPFhl65R7ww
time: o(logn)
space: o(1)

*/
class Solution {
public:
    double findMedianSortedArrays_1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (auto num : nums1) res.push_back(num);
        for (auto num : nums2) res.push_back(num);
        sort(res.begin(), res.end());
        
        if (res.size() % 2 == 0)
            return (res[res.size() / 2 - 1] + res[res.size() / 2]) / 2.f;
        else
            return res[res.size() / 2];
    }

    double findMedianSortedArrays_2(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int l = 0, r = 0;
        while (l < nums1.size() && r < nums2.size()) {
            if (nums1[l] < nums2[r])
                res.push_back(nums1[l++]);
            else
                res.push_back(nums2[r++]);
        }
        while (l < nums1.size()) res.push_back(nums1[l++]);
        while (r < nums2.size()) res.push_back(nums2[r++]);
        
        if (res.size() % 2 == 0)
            return (res[res.size() / 2 - 1] + res[res.size() / 2]) / 2.f;
        else
            return res[res.size() / 2];
    }

    double findMedianSortedArrays_3(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays_3(nums2, nums1);

        int l = 0, r = n1;
        while (l<=r) {
            auto px = (l+r) / 2;
            auto py = (n1 + n2 + 1) / 2 - px;

            auto x1 = (px == 0) ? INT_MIN : nums1[px-1];
            auto x2 = (px == n1) ? INT_MAX : nums1[px];
            
            auto y1 = (py == 0) ? INT_MIN : nums2[py-1];
            auto y2 = (py == n2) ? INT_MAX : nums2[py];

            if (x1 <= y2 && y1 <= x2) {
                if ((n1+n2) % 2 == 0) return (max(x1,y1) + min(x2,y2)) / 2.f;
                else return max(x1,y1);
            }
            else if (x1 <= y2) l = px + 1;
            else r = px - 1;
        }
        return -1;
    }

    double findMedianSortedArrays_4(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays_3(nums2, nums1);

        int l = 0, r = n1;
        while (l<=r) {
            auto px = (l+r) / 2;
            auto py = (n1 + n2 + 1) / 2 - px;
            auto x1 = (px == 0) ? INT_MIN : nums1[px-1];
            auto x2 = (px == n1) ? INT_MAX : nums1[px];
            auto y1 = (py == 0) ? INT_MIN : nums2[py-1];
            auto y2 = (py == n2) ? INT_MAX : nums2[py];

            if (x1 <= y2 && y1 <= x2) {
                if ((n1 + n2) % 2 == 0) return (max(x1, y1) + min(x2, y2)) / 2.f;
                else return max(x1, y1);
            }
            else if (x1 < y2) l = px + 1;
            else r = px - 1;
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedianSortedArrays_3(nums1, nums2);
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
