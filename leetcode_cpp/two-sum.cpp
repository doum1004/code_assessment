#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/two-sum/

// [2, 7, 11, 15] t = 9
// Solution. one-path map, two-path map
// answerMap
// time: o(n): one-path(iternate and put o(n)) two-path(generate and iterate o(2n))
// space: o(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // one path map
        auto map = unordered_map<int, int>();
        for (int i=0; i<nums.size(); ++i) {
            if (map.find(nums[i]) != map.end()) {
                return vector<int> {map[nums[i]], i};
            }
            auto ans = target - nums[i];
            map[ans] = i;
        }
        return vector<int>();
    }
};

int main()
{
    auto input1 = vector<int>{2, 7, 11, 15};
    auto input2 = vector<int>{3, 2, 4};
    auto input3 = vector<int>{-3,4,3,90};
    assert(Solution().twoSum(input1, 9) == (vector<int>{0, 1}));
    assert(Solution().twoSum(input1, 13) == (vector<int>{0, 2}));
    assert(Solution().twoSum(input1, 18) == (vector<int>{1, 2}));
    assert(Solution().twoSum(input2, 6) == (vector<int>{1, 2}));
    assert(Solution().twoSum(input2, 6) == (vector<int>{1, 2}));
    assert(Solution().twoSum(input3, 0) == (vector<int>{0, 2}));
    return 0;
}