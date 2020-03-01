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
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        auto n1 = nums1.size();
        auto n2 = nums2.size();

        int low = 0, high = n1;
        while (low <= high) {
            auto p1 = (low + high) / 2;
            auto p2 = (nums1.size() + nums2.size() + 1) / 2 - p1;

            auto maxLeft_p1 = (p1 == 0) ? INT_MIN : nums1[p1 - 1];
            auto minRight_p1 = (p1 == nums1.size()) ? INT_MAX : nums1[p1];

            auto maxLeft_p2 = (p2 == 0) ? INT_MIN : nums2[p2 - 1];
            auto minRight_p2 = (p2 == nums2.size()) ? INT_MAX : nums2[p2];

            if (maxLeft_p1 <= minRight_p2 && maxLeft_p2 <= minRight_p1) {
                if ((n1 + n2) % 2 == 0) {
                    return ((double)max(maxLeft_p1, maxLeft_p2) + (double)min(minRight_p1, minRight_p2)) / 2;
                }
                else
                {
                    return max(maxLeft_p1, maxLeft_p2);
                }
            }
            else if (maxLeft_p1 < maxLeft_p2) {
                // move right
                low = p1 + 1;
            }
            else {
                // move left
                high = p1 - 1;
            }
        }

        return -1;
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