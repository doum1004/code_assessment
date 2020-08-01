#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

solution1. store set and find expect in one iteration
o(n) / o(n)

solution2. sliding window
o(n) / o(1)

*/


class Solution {
public:
    vector<int> twoSum_sol1(vector<int>& numbers, int target) {
        unordered_map<int,int> s;
        for (int i=0; i<numbers.size(); ++i) {
            int expect = target - numbers[i];
            if (s.find(expect) != s.end()) {
                return {s[expect], i+1};
            }
            s[numbers[i]] = i+1;
        }
        
        return {};
    }
    
    vector<int> twoSum_sol2(vector<int>& numbers, int target) {
        int l=0, r = numbers.size()-1;
        while (l<r) {
            auto sum = numbers[l] + numbers[r];
            if (sum == target) {
                return {l+1, r+1};
            }
            else if (sum < target) {
                l++;
            }
            else {
                r--;
            }
        }
        return {};
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        //return twoSum_sol1(numbers, target);
        return twoSum_sol2(numbers, target);
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
