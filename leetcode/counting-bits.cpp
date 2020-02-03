#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/counting-bits

// Soluiton1. popcount bitmanipulation (pop the least 1)
// time o(nk) k: number of bit in x
// space o(n) ans
ex) 3
11 -> 10 -> 01 -> 0 = count(3)

int count
for (count=0; n!=0; count++)
    n &= n-1;
    
// Soluiton2. bitmanipulation f(x) = f(x & (x-1)) + 1 with bp
time: o(n)
space: o(n) ans
ex) 3
11 = 10(which is 11 & 10) + 1

*/

class Solution {
public:
    int popcount(int num) {
        int count=0;
        for (;num!=0;count++)
            num &= num-1;
        return count;
    }
    
    vector<int> countBits_popcount(int num) {
        vector<int> ans;
        for (int i=0; i<=num; i++)
            ans.push_back(popcount(i));
        return ans;
    }
    
    vector<int> countBits_dp(int num) {
        vector<int> ans(num+1);
        for (int i=1; i<=num; i++)
            ans[i] = ans[i & (i-1)] + 1;
        return ans;
    }
    
    vector<int> countBits(int num) {
        //return countBits_popcount(num);
        return countBits_dp(num);
    }
};

int main()
{
    auto expected1 = vector<int> {0, 1, 1};
    assert(Solution().countBits(2)
        == (expected1));
    auto expected2 = vector<int> {0, 1, 1, 2, 1, 2};
    assert(Solution().countBits(5)
        == (expected2));

    return 0;
}
