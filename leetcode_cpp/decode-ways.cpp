#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/decode-ways/

'' return 0

dp[0] = 1
dp[1] = '1' 1. since '1' != '0'
dp[2] = '12' 2 [(1,2), (12)] = dp[0] + dp[1]
dp[3] = '123' 3 [(1,2,3), (12,3), (1,23)] = dp[1](since 23 is avaiable) + dp[2]](since 3 is avaiable)
dp[4] = '1234' 4 [(1,2,3,4) (1,23,4) (12,3,4)] = dp[3](since 4 is avaiable). no for dp[2] since 34 is not avaiable

Solution1. DP with vector
// time: o(n)
// space: o(n). dp

ex) 1234
dp[0] = 1. '' can be decoded
dp[1] = 1. '1'. 1' can be decoded

loop from here
dp[2] = 2. '12'. '12' can be decoded(>=10 <=26). dp[2] += dp[0]. '2' can be decoded(!=0). dp[2] += dp[1]
dp[3] = 3. '123'. '23' can be decoded. dp[3] += dp[1]. '3' can be decoded. dp[3] += dp[2]
dp[4] = 3. '1234'. '34' can not be decoded. '4' can be decoded. dp[4] += dp[3]

dp table
0 (''): 1
1 ('1'): 1
2 ('12'): 2
3 ('123'): 3
4 ('1234'): 3
ans dp[4]

Solution2. DP with no vector
// time: o(n)
// space: o(1). constant dp

*/

class Solution {
public:
    int numDecodings_dp(string &s) {
        if (s.size() == 0) return 0;
        
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = s[0] != '0';
        
        for (int i=2; i<=s.size(); ++i) {
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) dp[i] += dp[i-2];
            if (s[i-1] != '0') dp[i] += dp[i-1];
        }
        
        return dp.back();
    }
    
    int numDecodings_dp_nospace(string &s) {
        if (s.size() <= 0) return s.size();
        
        int pre = 1;
        int cur = s[0] != '0';
        for (int i=2; i<=s.size(); ++i) {
            int temp = 0;
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) temp += pre;
            if (s[i-1] != '0') temp += cur;
            
            pre = cur;
            cur = temp;
        }
        
        return cur;
    }
    
    int numDecodings(string s) {
        return numDecodings_dp(s);
        //return numDecodings_dp_nospace(s);
    }
};

int main()
{
    assert(Solution().numDecodings("1") == 1);
    assert(Solution().numDecodings("12") == 2);
    assert(Solution().numDecodings("123") == 3);
    assert(Solution().numDecodings("1234") == 3);
    assert(Solution().numDecodings("12345") == 3);
    assert(Solution().numDecodings("0") == 0);
    assert(Solution().numDecodings("226") == 3);

    return 0;
}