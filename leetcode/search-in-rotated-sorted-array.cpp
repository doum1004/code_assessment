#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/
// o(log(n)) -> bin search
// find pivot by bin search
// 4 5 6 7 0 1 2
//     p (n)       -> v[p] > v[n] = false -> v[0] < v[p] ? right : left
//           p (n)
//       p (n) -> bingo
// pivot_index = 5

// find target (0)
// 4 5 6 7 0 1 2
// v[0] < t ? left : right of rotation
//           p
//         p -> bingo
// return p


class Solution {
public:
    int binsearch(vector<int>& nums, int target, int l, int r) {
        if (l < 0 || l > r || r >= nums.size()) return -1;
        
        while (l<=r) {
            auto mid = (l+r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }
        
        // find pivot
        auto pivot = 0;
        int l = 0, r = nums.size()-1;
        if (nums[l] > nums[r]) {
            while (l<=r) {
                auto mid = (l + r) / 2;
                if (nums[mid] > nums[mid + 1]) {
                    pivot = mid + 1;
                    break;
                }
                
                if (nums[l] > nums[mid]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        
        l = 0, r = nums.size() - 1;
        if (pivot != 0) {
            if (nums[0] > target) {
                l = pivot;
            }
            else {
                r = pivot-1;
            }
        }
        return binsearch(nums, target, l, r);
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