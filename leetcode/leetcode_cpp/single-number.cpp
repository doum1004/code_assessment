#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/single-number/

Solution1. Iterate. Map count
time: o(n)
space: o(n)

// Solution2. sort and iterate
// time: nlogn
// space: o(1)
sort(nums)
iterate nums
    if (nums[i] == nums[i+1])
        i = i+1
    else
        ans = nums[i]
return ans

// Solution3. math 2 * sum(set(sum)) - sum
// time: o(n)
// space: o(n) : set
2,2,1 -> set -> 2,1
2 * sum(set(sum)) - sum
6 - 5 = 1

// Solution4. bit manipulation (xor)
// time: o(n)
// space: o(1)
1 2 3 3 2
0 ^ n = n
n ^ n = 0

n ^= 1 -> 001
n ^= 2 -> 011
n ^= 3 -> 111
n ^= 3 -> 011
n ^= 2 -> 001

// Solution5. using set
// time: o(n)
// space: o(n)
iterate nums
    set.find(n) != end
        erase
    else
        set.insert(n)
return set[0]


*/

class Solution {
public:
    int singleNumber_1(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) m[n]++;
        for (auto it : m) if (it.second == 1) return it.first;
        return 0;
    }

    int singleNumber_2(vector<int>& nums) {
        if (!nums.size()) return 0;

        sort(nums.begin(), nums.end());
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                if (i == nums.size() - 1)
                    return nums[i];
                else if (nums[i] != nums[i+1])
                    return nums[i];
            }
        }
            
        return nums[0];
    }

    int singleNumber_bitmanipulation(vector<int>& nums) {
        int i = 0;
        for (auto &n : nums) {
            i ^= n;
        }
        return i;
    }
    
    int singleNumber_math(vector<int>& nums) {
        unordered_set<int> s;
        auto sum_set = 0;
        auto sum = 0;
        for (auto &n:nums) {
            if (s.find(n) == s.end()) {
                s.insert(n);
                sum_set += n;
            }
            sum += n;
        }
        
        return 2 * sum_set - sum;
    }
    
    int singleNumber(vector<int>& nums) {
        //return singleNumber_math(nums);
        return singleNumber_bitmanipulation(nums);
    }
};

int main()
{
    auto input1 = vector<int> {2,2,1};
    assert(Solution().singleNumber(input1)
        == 1);
    auto input2 = vector<int> {4,1,2,1,2};
    assert(Solution().singleNumber(input2)
        == 4);
    return 0;
}