#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum2(vector<int>& numbers, int target) {
        vector<int> ans;
        if (numbers.size() < 2) return ans;
        
        // store result of intersect with index
        auto store_intersection = unordered_map<int, int>();
        int i = 0;
        for (auto n : numbers) {
            store_intersection[target - n] = i++;
        }

        for (int i=0; i<numbers.size()-1; i++) {
            auto it = store_intersection.find(numbers[i]);
            if (it != store_intersection.end()) {
                auto j = it->second;
                ans.push_back(i < j ? i + 1 : j + 1);
                ans.push_back(i < j ? j + 1 : i + 1);
                break;
            }
        }

        return ans;
    }

    vector<int> twoSum1(vector<int>& numbers, int target) {
        if (numbers.size() < 2) return {};
        
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            auto sum = numbers[l] + numbers[r];
            if (sum == target) return {l + 1, r + 1};
            else if (sum > target) r--;
            else l++;
        }

        return {};
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        return twoSum1(numbers, target);
        //return twoSum2(numbers, target);
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