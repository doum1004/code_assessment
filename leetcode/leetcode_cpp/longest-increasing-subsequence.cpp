#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

/**
https://leetcode.com/problems/longest-increasing-subsequence/

//Solution1. Greedy (not acceptable)
//time: o(2^n)
//space: o(n^2) recursion

//Solution2. Greedy with memorization
//time: o(n^2)
//space: o(n^2) recursion

//Solution3. dp.
//time: o(n^2)
//space: o(n). dp

table will store number of availibility from that node.
from the end to begin, check avaiable item's table to get max

1. create table to save max possibility from end.
1.1 loop i from end to begin
1.1.1 cur = 1
1.1.2 loop j from i+1 to end
1.1.2.1 if (nums[i] < nums[j]) cur = max(cur, t[j])
1.1.3 t[i] = cur; res = max(res, cur)

//solution4. dp with binary search (check solution)
https://www.youtube.com/watch?v=S9oUiVYEq7E&t=307s
//time: o(nlogn)
//space: o(n)

1. loop from begin and store and update sequence of values.
2. compare last value of table and it is not larger than, replace it in table (binary search)
3. return length of table
0 8 4 12 2
i
table [0]

0 8 4 12 2 (0 < 8) add
  i
table [0 8]

0 8 4 12 2 (8 > 4) replace
    i
table [0 4]

0 8 4 12 2 (4 < 12) add
      i
table [0 4 12]

0 8 4 12 2 (12 > 2) replace
         i
table [0 2 12]


//solution5. dp with binary search and no extra space
https://leetcode.com/problems/longest-increasing-subsequence/discuss/74855/Short-C%2B%2B-STL-based-solution%3A-O(n-log-n)-time-O(1)-space-with-explanation
//time: o(nlogn)
//space: o(1)

*/

class Solution {
public:
    int greedy(vector<int>& nums, int pre, int cur) {
        if (cur == nums.size()) return 0;
        int count_a = 0;
        if (pre == -1 || nums[pre] < nums[cur])
            count_a = 1 + greedy(nums, cur, cur+1);
        int count_b = greedy(nums, pre, cur+1);
        return max(count_a, count_b);
    }
    
    int lengthOfLIS_greedy(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        return greedy(nums, -1, 0);
    }
    
    int greedy_memorization(vector<int>& nums, vector<vector<int>>& m, int pre, int cur) {
        if (cur == nums.size()) return 0;
        if (m[pre+1][cur] > -1) {
            return m[pre+1][cur];
        }
        
        int count_a = 0;
        if (pre == -1 || nums[pre] < nums[cur])
            count_a = 1 + greedy_memorization(nums, m, cur, cur+1);
        int count_b = greedy_memorization(nums, m, pre, cur+1);
        m[pre+1][cur] = max(count_a, count_b);
        return m[pre+1][cur];
    }
    
    int lengthOfLIS_greedy_memorization(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        vector<vector<int>> m(nums.size()+1, vector<int> (nums.size(), -1));
        return greedy_memorization(nums, m, -1, 0);
    }
    
    int lengthOfLIS_dp(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        
        vector<int> t(nums.size(), 1);
        int res = 1;
        for (int i=nums.size()-2; i>=0; --i) {
            int cur = 1;
            for (int j=i+1; j<nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    cur = max(cur, 1+t[j]);
                }
            }
            t[i] = cur;
            res = max(res, cur);
        }
        return res;
    }
    
    int lengthOfLIS_nlogn(vector<int>& nums) {
        vector<int> res;
        for (auto &n:nums) {
            if (res.size() == 0 || res[res.size()-1] < n) res.push_back(n);
            else {
                auto it = lower_bound(res.begin(), res.end(), n);
                *it = n;
            }
        }
        return res.size();
    }
    
    int lengthOfLIS_nlogn_nospace(vector<int>& nums) {
        auto m = nums.begin();
        for (auto &n:nums) {
            auto it = lower_bound(nums.begin(), m, n);
            *it = n;
            if (it == m) m++;
        }
        return m-nums.begin();
    }
    
    int lengthOfLIS(vector<int>& nums) {
        //return lengthOfLIS_greedy(nums);
        //return lengthOfLIS_greedy_memorization(nums);
        //return lengthOfLIS_dp(nums);
        //return lengthOfLIS_nlogn(nums);
        return lengthOfLIS_nlogn_nospace(nums);
    }
};

int main()
{
    auto input1 = vector<int> {10,9,2,5,3,7,101,18};
    assert(Solution().lengthOfLIS(input1) == (4));
    
    return 0;
}