#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int binSearch(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            auto mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return -1;
    }

    int searchTwoPath(vector<int>& nums, int target) {
        auto n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;

        // find the smalleaset
        int l = 0, r = n - 1;
        auto pivot = 0;
        if (nums[l] < nums[r]) {
            pivot = 0;
        }
        else {
            while (l<=r) {
                pivot = (l + r) / 2;
                if (nums[pivot] > nums[pivot + 1]) {
                    pivot++;
                    break;
                }
                if (nums[pivot] < nums[l]) {
                    r = pivot - 1;
                }
                else {
                    l = pivot + 1;
                }
            }
        }

        if (pivot == 0) {
            return binSearch(nums, target, 0, nums.size() - 1);
        }
        else if (target < nums[0]) {
            return binSearch(nums, target, pivot, n - 1);
        }
        
        return binSearch(nums, target, 0, pivot);
    }

    int searchOnePath(vector<int>& nums, int target) {
        // int start = 0, end = nums.size() - 1;
        // while (start <= end) {
        //     int mid = start + (end - start) / 2;
        //     if (nums[mid] == target) return mid;
        //     else if (nums[mid] >= nums[start]) {
        //         if (target >= nums[start] && target < nums[mid]) end = mid - 1;
        //         else start = mid + 1;
        //     }
        //     else {
        //         if (target <= nums[end] && target > nums[mid]) start = mid + 1;
        //         else end = mid - 1;
        //     }
        // }
        // return -1;
    }

    int search(vector<int>& nums, int target) {
        return searchOnePath(nums, target);
        //return searchTwoPath(nums, target);
    }
};

int main()
{
    auto input1_1 = vector<int> {4,5,6,7,0,1,2};
    assert(Solution().search(
        input1_1, 0
    ) == 4);
    auto input2_1 = vector<int> {1};
    assert(Solution().search(
        input2_1, 0
    ) == -1);
    auto input3_1 = vector<int> {1};
    assert(Solution().search(
        input3_1, 1
    ) == 0);
    auto input4_1 = vector<int> {1,3};
    assert(Solution().search(
        input4_1, 0
    ) == -1);
    auto input5_1 = vector<int> {3,1};
    assert(Solution().search(
        input5_1, 3
    ) == 0);
    auto input6_1 = vector<int> {5,1,3};
    assert(Solution().search(
        input6_1, 0
    ) == -1);
    auto input7_1 = vector<int> {8,9,2,3,4};
    assert(Solution().search(
        input7_1, 9
    ) == 1);
    return 0;
}