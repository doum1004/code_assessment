#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/next-permutation/

// Solution1. built in function

// Solution2. two passes
// time: o(n)
// space: o(1)

1 2 3 4 -> 1 2 4 3 -> 1 3 2 4 -> 1 3 4 2 -> 1 2 3 4
    * %      *   %        * %      *   %  
  4 3 2 1 -> 1 2 3 4
*
    
1. find * from right which is smaller than before
2. in case there is *, reverse all, otherwise do 3~5
3. find % from end which is larger than *
4. swap(*,%)
5. and reverse after *

*/

class Solution {
public:
    void nextPermutation_builtin(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
    
    void nextPermutation_twopasses(vector<int>& nums) {
        int n = nums.size();
        
        int i;
        for (i=n-2; i>=0; --i) {
            if (nums[i] < nums[i+1]) break;
        }
        
        if (i<0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            // find smallest in largers
            int j;
            for (j=n-1; j>=i+1; --j) {
                if (nums[i] < nums[j]) break;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        //nextPermutation_builtin(nums);
        nextPermutation_twopasses(nums);
    }
};

int main()
{
    auto input1 = vector<int> {1,2,3};
    auto expect1 = vector<int> {1,3,2};
    Solution().nextPermutation(input1);
    assert(input1 == expect1);

    return 0;
}