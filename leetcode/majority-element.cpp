#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/majority-element/

// Solution1 hashmap
// map for number and count. and return when it hit more than n/2
// time: o(n)
// space: o(n)

// Solution2 sort (nth_lement)
// since the majority element has more than n / 2. n / 2 th element must be majority number
// time: o(nlogn)
// space: o(1)

// Soluiton3 bit manipulation
// 0 to 31 create mask(1<<i) and iterate nums to check mask hit (n & mask) hit++
// if hit > n/2 then ans |= mask
// time: o(n * m) m = 32(bit numbers)
// space: o(1)

*/

class Solution {
public:
    int majorityElement_sort(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }
    
    int majorityElement_hashmap(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int i=0; i<n; i++) {
            auto num = nums[i];
            map[num]++;
            if (map[num] > (n / 2)) return num;
        }
        return -1;
    }
    
    int majorityElement_bitmapnipulation(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i=0; i<32; ++i) {
            int hit = 0;
            auto mask = 1 << i;
            for (auto &n:nums) {
                if (n & mask)
                    hit++;
            }
            
            if (hit > n/2)
                ans |= mask;
        }
        return ans;
    }
    
    int majorityElement(vector<int>& nums) {
        //return majorityElement_sort(nums);
        //return majorityElement_hashmap(nums);
        return majorityElement_bitmapnipulation(nums);
    }
};

int main()
{
    auto input1 = vector<int> { 3, 2, 3 };
    assert(Solution().majorityElement(input1) == (3));
    auto input2 = vector<int> { 2, 2, 1, 1, 1, 2, 2 };
    assert(Solution().majorityElement(input2) == (2));

    return 0;
}