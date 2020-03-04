#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/sort-colors/

//Soltuion1. two passes with counter
//time: o(n). 2n
//space: o(1). 3(colors)

//Solution2. one passes. iterate by cur and put 0 in left, 2 in right
//time: o(n)
//space: o(1)

*/

class Solution {
public:
    void sortColors_counting(vector<int>& nums) {
        vector<int> counter(3, 0);
        for (auto &num:nums) {
            counter[num]++;
        }
        
        int p=0;
        for (int i=0; i<3; ++i) {
            auto count = counter[i];
            for (int j=1; j<=count; ++j) {
                nums[p++] = i;
            }
        }
    }
    
    void sortColors_onepass(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=n-1,cur=0;
        while (cur<=r) {
            if (nums[cur] == 0) {
                swap(nums[cur++], nums[l++]);
            }
            else if (nums[cur] == 2) {
                swap(nums[cur], nums[r--]);
            }
            else {
                cur++;
            }
        }
    }
    
    void sortColors(vector<int>& nums) {
        //return sortColors_counting(nums);
        return sortColors_onepass(nums);
    }
};

int main()
{
    auto input1 = vector<int> {2,0,2,1,1,0};
    auto output1 = vector<int> {0,0,1,1,2,2};
    Solution().sortColors(input1);
    assert(input1 == output1);

    auto input2 = vector<int> {1};
    auto output2 = vector<int> {1};
    Solution().sortColors(input2);
    assert(input2 == output2);

    auto input3 = vector<int> {2,0,1};
    auto output3 = vector<int> {0,1,2};
    Solution().sortColors(input3);
    assert(input3 == output3);

    return 0;
}