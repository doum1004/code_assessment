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
 
Solution1. sort and find 1/2 index
time o(nlogn) o(nlogk) nth_element
space o(1)

Solution2. hash map if hit value is over 1/2 return
time o(n)
space o(n)

Soltuion3. bit manipulation
time o(n * m) : m=32bit
space o(1)
1. int32 iterate i o to 31
    1.1 iternate nums
        1.1.1 hit count of i'th bit
    1.2 if hit count > n/2, then add i bit in ans
ex) [2,3,2] [0010 0011 0010]
i=0 hit 1 (001'1')
i=1 hit 3 (00'1'0 00'1'1 00'1'0) ans += 1 << 1 = 0010 = 2
  
  
Solution4. randomization. take rand candidate and count
time: o(infinite) : but runtime is far faster than linear. because majority is more than half

Solution5. Moore voting
time o(n)
space o(1)
vote count if count goes 0 and change candidate
last stand man is the majority
ex) 2 3 3 2 2
i=0, count=0, candidate=2, count=1
i=1, count=1->0
i=2, count=0, candidate=3, count=1
i=3, count=1->0
i=4, count=0, candidate=2, count=1
return candidate


*/

class Solution {
public:
    int majorityElement_sort(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size()/2];
    }
    
    int majorityElement_hash(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto &n:nums) {
            m[n]++;
            if (m[n] > nums.size() / 2) return n;
        }
        return -1;
    }
    
    int majorityElement_bit(vector<int>& nums) {
        auto ans = 0;
        for (int i=0; i<32; ++i) {
            auto hit = 0;
            for (auto &n:nums) {
                hit += n >> i & 1;
            }
            ans += (hit > nums.size() / 2) << i;
        }
        return ans;
    }
    
    int majorityElement_rand(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        srand(time(NULL));
        while (true) {
            ans = nums[rand() % n];
            auto counter = 0;
            for (auto &n:nums) {
                if (n == ans) counter++;
            }
            if (counter > n / 2) break;
        }
        return ans;
    }
    
    int majorityElement_voting(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (auto &n:nums) {
            if (count == 0) candidate = n;
            count += n == candidate ? 1 : -1;
        }
        return candidate;
    }
    
    int majorityElement(vector<int>& nums) {
        //return majorityElement_sort(nums);
        //return majorityElement_hash(nums);
        //return majorityElement_bit(nums);
        //return majorityElement_rand(nums);
        return majorityElement_voting(nums);
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