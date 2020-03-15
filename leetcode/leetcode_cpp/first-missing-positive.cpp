#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_set>

using namespace std;

/**
https://leetcode.com/problems/first-missing-positive/

solution1. hash map of nums and check from 1
// time: o(n)
// space: o(n)

solution2. sort
// time: o(nlogn)
// space: o(1)

solution2. bit manipulation on positive values. and check bit. (not accepted as overflow)
// time: o(n)
// space: o(1)

solution4. put num in right place (for positive in range of n)
// time: o(n) 
// space: o(1)

1. loop i in 0~n-1
1.1 inner loop (nums[i] > 0 && nums[i] <=n && nums[nums[i]-1] != nums[i]: swap(nums[nums[i-1]-1], nums[i])
2. loop i in 1~n
2.1 check existance of right number

*/

class Solution {
public:
    int firstMissingPositive_map(vector<int>& nums) {
        unordered_set<int> m;
        for (auto &n:nums) {
            m.insert(n);
        }
        
        for (int i=1; i<=nums.size()+1; ++i) {
            if (!m.count(i)) return i;
        }
        return -1;
    }
    
    int firstMissingPositive_sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int cur = 1;
        for (int &n:nums) {
            if (n < cur) continue;
            if (n > cur) return cur;
            cur++;
        }
        
        return cur;
    }
    
    int firstMissingPositive_bit(vector<int>& nums) {
        int bit = 0;
        for (auto n:nums) {
            if (n<1) continue;
            bit ^= 1 << n; // overflow 
        }
        
        for (int i=1; i<=nums.size()+1; ++i) {
            if (!(bit >> i & 1)) return i;
        }
        
        return -1;
    }
    
    int firstMissingPositive_putrightplace(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        
        for (int i=1; i<=n; ++i) {
            if (i != nums[i-1]) return i;
        }
        
        return n+1;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        //return firstMissingPositive_map(nums);
        //return firstMissingPositive_sort(nums);
        //return firstMissingPositive_bit(nums);
        return firstMissingPositive_putrightplace(nums);
    }
};

int main()
{
    auto input1 = vector<int> {1,2,0};
    assert(Solution().firstMissingPositive(input1) == (3));

    auto input2 = vector<int> {3,4,-1,1};
    assert(Solution().firstMissingPositive(input2) == (2));

    auto input3 = vector<int> {7,8,9,11,12};
    assert(Solution().firstMissingPositive(input3) == (1));

    return 0;
}
