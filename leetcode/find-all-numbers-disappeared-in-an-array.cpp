#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

input: 1 2 2
output: 3

condition o(n) o(1)

// Solution1. hash map to count
// time: o(n)
// space: o(n) hash

// Solution2. ans modifiation (time exceeded)
// time: o(n) n + n + n
// space: o(1) except ans
1. put nums in ans o(n)
1 2 3
2. iterate input and set 0 o(n)
0 0 3
3. find 0 and erase o(n)

// Solution3. in place modifiation
// time: o(n) : n + n
// space: o(1) except ans
1. iterate and mark -1 on the index which comes from value
1 2 2
-1 -2 2
index 2 is positive so return 3

for i to n
    nums[i] = abs(nums[i]) * -1;
    
for i to n
    if (nums[i] < 0) ans.push


*/

class Solution {
public:
    vector<int> findDisappearedNumbers_ans_modifiation(vector<int>& nums) {
        vector<int> ans;
        
        for (int i=0; i<nums.size(); ++i) {
            ans.push_back(i+1);
        }
        
        for (int i=0; i<nums.size(); ++i) {
            ans[nums[i] - 1] = 0;
        }
        
        for (int i=0; i<ans.size(); ++i) {
            if (ans[i] == 0) {
                ans.erase(ans.begin() + i);
                i--;
            }
        }
        return ans;
    }
    
    vector<int> findDisappearedNumbers_inplace_modification(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i) {
            auto index = abs(nums[i]) - 1;
            nums[index] = abs(nums[index]) * -1;
        }
        
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] > 0) ans.push_back(i+1);
        }
        return ans;
    }
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //return findDisappearedNumbers_ans_modifiation(nums);
        return findDisappearedNumbers_inplace_modification(nums);
    }
};

int main()
{
    auto input1 = vector<int> { 4,3,2,7,8,2,3,1 };
    auto expect1 = vector<int> { 5,6 };
    assert(Solution().findDisappearedNumbers(input1) == (expect1));

    return 0;
}