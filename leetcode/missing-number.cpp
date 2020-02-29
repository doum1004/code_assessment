#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/missing-number/

//solution1. prepare set and mark
// time: o(n). 2n
// space: o(n)

// solution2. sort and iterate
// time: o(nlogn + n)
// space: o(1)

// solution3. bit manipulation (xor)
// time: o(n)
// space: o(1)

ex) 0 1 3 (size:2)
size ^ (0 to size-1) ^ (values)
3 ^ (0 ^ 1 ^ 2) ^ (0 ^ 1 ^ 3)
= (0 ^ 0) ^ (1 ^ 1) ^ (3 ^ 3) ^ 2
= 0 ^ 0 ^ 0 ^ 2
= 2

// solution4. math(gauss). get expected sum. and extract actual sum.
// time: o(n)
// space: o(1)

*/

class Solution {
public:
    int missingNumber_list(vector<int>& nums) {
        vector<bool> l(nums.size()+1,false);
        for (auto &n:nums) l[n] = true;
        for (int i=0; i<l.size(); ++i) if (l[i] == false) return i;
        return -1;
    }

    int missingNumber_sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ++i) {
            if (i != nums[i]) return i;
        }
        return nums.size();
    }
    
    int missingNumber_bitmanipulation(vector<int>& nums) {
        int missing = nums.size();
        for (int i=0; i<nums.size(); ++i) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
    
    int missingNumber_gauss(vector<int>& nums) {
        int expected = nums.size() * (nums.size() + 1) / 2;
        int actual = 0;
        for (auto &n:nums) actual += n;
        return expected-actual;
    }
    
    int missingNumber(vector<int>& nums) {
        //return missingNumber_list(nums);
        //return missingNumber_sort(nums);
        //return missingNumber_bitmanipulation(nums);
        return missingNumber_gauss(nums);
    }
};

int main()
{
    auto input1 = vector<int> {3,0,1};
    assert(Solution().missingNumber(input1) == 2);
    auto input2 = vector<int> {9,6,4,2,3,5,7,0,1};
    assert(Solution().missingNumber(input2) == 8);
    return 0;
}