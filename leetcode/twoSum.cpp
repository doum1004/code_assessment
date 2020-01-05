#include <iostream>
#include <vector>
#include <cassert>
#include "../../utils.h"

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    auto n = nums.size();
    auto map = unordered_map<int, int>(n);
    for (int i=0; i<n; i++) {
        map[nums[i]] = i;
    }
    
    vector<int> answer(0);
    for (int i=0; i<n; i++)
    {
        auto complement = target - nums[i];
        if (map.find(complement) != map.end() && map[complement] != i)
            return vector<int>{i, map[complement]};
    }
    throw new exception();
    //vector<int> answer(0);
    // for (int i = 0; i<nums.size() - 1; i++)
    // {
    //     for (int j = i+1; j<nums.size(); j++)
    //     {
    //         if (nums[i] + nums[j] == target)
    //         {
    //             answer.push_back(i);
    //             answer.push_back(j);
    //             break;
    //         }
    //     }
    // }

    //return answer;
}

int main()
{
    auto input1 = vector<int>{2, 7, 11, 15};
    auto input2 = vector<int>{3, 2, 4};
    auto input3 = vector<int>{-3,4,3,90};
    assert(twoSum(input1, 9) == (vector<int>{0, 1}));
    assert(twoSum(input1, 13) == (vector<int>{0, 2}));
    assert(twoSum(input1, 18) == (vector<int>{1, 2}));
    assert(twoSum(input2, 6) == (vector<int>{1, 2}));
    assert(twoSum(input2, 6) == (vector<int>{1, 2}));
    assert(twoSum(input3, 0) == (vector<int>{0, 2}));
    return 0;
}