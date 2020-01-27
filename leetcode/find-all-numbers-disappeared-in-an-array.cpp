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

Condition: time: o(n), space: o(1) except return

// Solution 1. accepted
// time: o(2n)
// space: o(1) except return value
ex) 1 2 3 3
-1 -2 -3 3
ans: 4(index:3)


1. iterate vector
1.1 get index from num (nums[i] - 1)
1.2 set value of -1 multiply result

2. iterate vector
2.1 set index when it's value over 0 (which never appear)

// Soution 2.
// time: o(3n)
// space: o(1) except return
ex) 1 2 2 4

1. vector to store n o(n)
1 2 3 4

2. Iterate vector and set if num appear o(n)
0 0 3 0

3. erase num==0 in vector o(n)

*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i) {
            auto index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] *= -1;
            }
        }
        
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] > 0) {
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};

int main()
{
    auto input1 = vector<int> { 4,3,2,7,8,2,3,1 };
    auto expect1 = vector<int> { 5,6 };
    assert(Solution().findDisappearedNumbers(input1) == (expect1));

    return 0;
}