#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

input: 2 7 11 15. target=9
output: vector [1, 2]

1. if not sorted
svae answer for each elements

2. if it is sorted
sling window
time: o(n)
space: o(1)

2 7 11 15
l       r
2+15 > 9 -> r--;

2 7 11 15
l    r
2+11 > 9 -> r--;

2 7 11 15
l r
2+7 > 9 -> r--;

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() < 1) return vector<int>();
        if (numbers.size() == 1) return (numbers[0] == target) ? vector<int> {1} : vector<int>();
        
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            auto sum = numbers[l] + numbers[r];
            if (sum == target) {
                return vector<int> {l + 1, r + 1};
            }
            else if (sum > target) {
                --r;
            }
            else {
                ++l;
            }
        }
        
        return vector<int>();
    }
    
    vector<int> twoSum2(vector<int>& numbers, int target) {
        // diff map to store answer
        auto diff = unordered_map<int, int>();
        for (int i=0; i<numbers.size(); ++i) {
            diff[target - numbers[i]] = i;
        }
        
        vector<int> ans;
        for (int i=0; i<numbers.size(); ++i) {
            if (diff.find(numbers[i]) != diff.end()) {
                auto j = diff[numbers[i]];
                ans.push_back((i < j) ? i + 1 : j + 1);
                ans.push_back((i < j) ? j + 1 : i + 1);
                return ans;
            }
        }
        return ans;
    }
};

int main()
{
    auto input1_1 = vector<int> {2,7,11,15};
    assert(Solution().twoSum(
        input1_1, 9
    ) == (vector<int> {1,2}));
    auto input2_1 = vector<int> {5,25,75};
    assert(Solution().twoSum(
        input2_1, 100
    ) == (vector<int> {2,3}));
    return 0;
}