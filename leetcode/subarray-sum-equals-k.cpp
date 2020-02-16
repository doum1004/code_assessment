#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/subarray-sum-equals-k/

// solution1. brute force
// time: o(n^2)
// space: o(1)
1 1 1 (2)
for i in 0~n
    for j in i~n
i=0 0~1
i=1 1~2

// Soluiton2. dp. map to store accumulate sum and count
Find if stored value is equal to cursum-target.
It means subtrating the value, then it can make a target after
add 0:1 at the beginning
// time: o(n)
// space: o(n)

3 1 2 -3 3. target 3. map: 0(1)
i=0 sum=3. expect 0. hit:0(1) count=1. map: 0(1) 3(1) 
i=1 sum=4. expect 1. hit:none count=1. map: 0(1) 3(1) 4(1)
i=2 sum=6. expect 3. hit:3(1) count=2. map: 0(1) 3(1) 4(1) 6(1)
i=3 sum=3. expect 0. hit:0(1) count=3. map: 0(1) 3(2) 4(1) 6(1)
i=4 sum=6. expect 3. hit:3(2) count=5. map: 0(1) 3(2) 4(1) 6(2)

ex) target 7. [3 4 4 3 -3 7] expect=sum-target
                    map: 0:1
i=0 sum=3 expect=-4 map: 0:1 3:1        count=0
i=1 sum=7 expect=0  map: 0:1 3:1 7:1    count=1
i=2 sum=11 expect=4 map: 0:1 3:1 7:1 11:1 count=1
i=3 sum=14 expect=7 map: 0:1 3:1 7:1 11:1 14:1 count=2
i=4 sum=11 expect=4 map: 0:1 3:1 7:1 11:2 14:1 count=2
i=5 sum=18 expect=11 map: 0:1 3:1 7:1 11:2 14:1 18:1 count=4

*/

class Solution {
public:
    int subarraySum_bruteforce(vector<int>& nums, int k) {
        int count = 0;
        for (int i=0; i<nums.size(); ++i) {
            int sum = 0;
            for (int j=i; j<nums.size(); ++j) {
                sum += nums[j];
                if (sum == k) count++;
            }
        }
        
        return count;
    }
    
    int subarraySum_dp(vector<int>& nums, int k) {
        unordered_map<int, int> dp;
        dp[0]++;
        
        int count = 0;
        int sum = 0;
        for (auto &n:nums) {
            sum += n;
            if (dp.find(sum-k) != dp.end()) count += dp[sum-k];
            dp[sum]++;
        }
        
        return count;
    }
    
    int subarraySum(vector<int>& nums, int k) {
        //return subarraySum_bruteforce(nums, k);
        return subarraySum_dp(nums, k);
    }
};

int main()
{
    auto input1 = vector<int> {1,1,1};
    assert(Solution().subarraySum(input1, 2)
        == 2);
    return 0;
}