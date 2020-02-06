#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/subarray-sum-equals-k/

// Solution1. brute force solution iterate two pointers and check sum hits k
// time: o(n^2)
// space: o(1)

// Soluiton2. map to store accumulate sum and count. and find if stored value is equal to cursum-target. It means after the sotred index to cur it can be target (add 0:1 at the beginning).
// time: o(n)
// space: o(n)
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
        int ans = 0;
        
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            auto sum = nums[i];
            if (sum == k) ans++;
            for (int j=i+1; j<n; ++j) {
                sum += nums[j];
                if (sum == k) ans++;
            }
        }
        
        return ans;
    }
    
    int subarraySum_map(vector<int>& nums, int k) {
        auto ans = 0, sum = 0;
        unordered_map<int, int> m;
        m[0]++;
        for (auto &n:nums) {
            sum += n;
            auto target = sum-k;
            if (m.find(target) != m.end()) ans += m[target];
            m[sum]++;
        }
        
        return ans;
    }
    
    int subarraySum(vector<int>& nums, int k) {
        //return subarraySum_bruteforce(nums, k);
        return subarraySum_map(nums, k);
    }
};

int main()
{
    auto input1 = vector<int> {1,1,1};
    assert(Solution().subarraySum(input1, 2)
        == 2);
    return 0;
}