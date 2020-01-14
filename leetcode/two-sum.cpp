#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //two path hash table (it can be one path)
        //time complexcity: o(n) + (o(n) * o(1)) -> o(n)
        //space complexcityL o(n)

        if (nums.size() < 2) return vector<int>();

        auto diff = unordered_map<int, int>();
        for (int i=0; i<nums.size(); ++i) {
            diff[target - nums[i]] = i;
        }
        
        for (int i=0; i<nums.size(); ++i) {
            auto num = nums[i];
            if (diff.find(num) != diff.end() && i != diff[num]) {
                return vector<int> {i, diff[num]};
            }
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