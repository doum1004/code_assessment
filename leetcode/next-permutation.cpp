#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/next-permutation/

1 2 3 -> 1 3 2 -> 2 1 3 -> 2 3 1 -> 3 1 2 -> 3 2 1 -> 1 2 3

1 2 3 4 -> 1 2 4 3 -> 1 3 2 4 -> 1 3 4 2 -> 1 4 2 3 -> 1 4 3 2 -> 2 1 3 4 -> 2 1 4 3 -> 2 3 1 4 -> 2 3 4 1 -> 2 4 1 3

1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 4 3 5 -> 1 2 4 5 3 -> 1 2 5 3 4 -> 1 2 5 4 3 -> 1 3 2 4 5

// solution1. built in
// time: o(n)
// space: o(1)

// solution2. swap, reverse
1. find largest index k (nums[k] < nums[k+1]), if not reverse all
2. find the largest index l > k (nums[k] < nums[l])
3. swap nums[k], nums[l]
4. reverse nums[k+1]
// time: o(n) : n + n + ... n
// space: o(1)

*/

class Solution {
public:
    void nextPermutation_1(vector<int>& nums) {
        next_permutation(begin(nums), end(nums));
    }
    
    void nextPermutation_2(vector<int>& nums) {
        int n = nums.size(), k, l;
        for (k = n-2; k>=0; --k) {
            if (nums[k] < nums[k+1]) {
                break;
            }
        }
        if (k < 0) reverse(nums.begin(), nums.end());
        else {
            for (l=n-1; l>k; --l) {
                if (nums[k] < nums[l]) break;
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin()+k+1, nums.end());
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        //nextPermutation_1(nums);
        nextPermutation_2(nums);
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