#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/3sum-closest/

// Solution1. Brute force. And little improve with sort.
// time: o(n^3)
// space: o(1)

// Solution2. Sort and two passes with three pointers
// time: o(n^2)
// space: o(1)

1. sort
2. Iterate in two passes
3. return if matches with target. otherwise, save cloest
4. move j, k
-2 -1 0 1 2 3 4 5 (target 7)
i   j           k
sum = 2. 2<11 ? j++ : k--

-2 -1 0 1 2 3 4 5 (target 11)
i     j         k
sum = 3. 3<11 ? j++ : k--

...

-2 -1 0 1 2 3 4 5 (target 11)
          i j   k
sum = 10. 10<11 ? j++ : k--

-2 -1 0 1 2 3 4 5 (target 11)
          i   j k
sum = 11. Done.

*/

class Solution {
public:
    int threeSumClosest_bruteforce(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        
        sort(nums.begin(), nums.end());
        
        int cloest = 0;
        int min_diff = INT_MAX;
        
        for (int i=0; i<n-2; ++i) {
            for (int j=i+1; j<n-1; ++j) {
                int pre_diff = INT_MAX;
                for (int k=j+1; k<n; ++k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    int cur_diff = abs(sum - target);
                    if (pre_diff < cur_diff) break;
                    
                    if (cur_diff < min_diff) {
                        min_diff = cur_diff;
                        cloest = sum;
                    }
                    
                    pre_diff = cur_diff;
                }
            }
        }
        
        return cloest;
    }
    
    int threeSumClosest_twopasses(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end()); //sort
        
        int cloest = nums[0] + nums[1] + nums[2];
        if (cloest == target) return target;
        
        for (int i=0; i<n-2; ++i) {
            int j = i+1, k = n-1;
            while (j<k) {
                auto sum = nums[i] + nums[j] + nums[k];                
                if (sum == target) return sum;
                if (abs(sum-target) < abs(cloest-target)) cloest = sum;
                
                if (sum > target) k--;
                else j++;
            }
        }
        return cloest;
    }
               
    int threeSumClosest(vector<int>& nums, int target) {
        //return threeSumClosest_bruteforce(nums, target);
        return threeSumClosest_twopasses(nums, target);
    }
};

int main()
{
    auto input1 = vector<int> {-1, 2, 1, -4};
    assert(Solution().threeSumClosest(input1, 1) == (2));
    return 0;
}