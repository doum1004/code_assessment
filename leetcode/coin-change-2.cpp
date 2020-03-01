#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

/**
https://leetcode.com/problems/coin-change-2/

// Solution1. DP
https://www.youtube.com/watch?v=_fgjrs570YE
// time: o(C*A). C(coins). A(amounts)
// space: o(A). dp(vector for amounts)

1. create dp table (it can be one vector since it uses previous)
2. calculate new dp with coin

amount=6, coins=[1,2,5]
  0 1 2 3 4 5 6
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1
2 1 1 2 2 3 3 4
5 1 1 2 2 3 4 5

1: (1)
2: (1 1) (2)
3: (1 1 1) (2 1)
4: (1 1 1 1) (1 1 2) (2 2)
5: (1 1 1 1 1) (1 1 1 2) (1 2 2) (5)
6: (1 1 1 1 1 1) (1 1 1 1 2) (1 1 2 2) (1 5) (2 2 2)

amount=6, coins=[2,5]
  0 1 2 3 4 5 6
0 0 0 0 0 0 0 0
2 1 0 1 0 1 0 1
5 1 0 1 0 1 1 1
f(x) = f(x) + f(x-coin)

*/

class Solution {
public:
    int change_dp(int amount, vector<int>& coins) {
        // create dp table or vector
        vector<int> cur(amount+1, 0);
        cur[0] = 1;
        
        sort(coins.begin(), coins.end());
        for (auto &coin:coins) {
            for (int i=coin; i<=amount; ++i) {
                cur[i] += cur[i - coin];
            }
        }
        return cur.back();
    }
    
    int change(int amount, vector<int>& coins) {
        return change_dp(amount, coins);
    }
};

int main()
{
    auto input1 = vector<int> {1,2,5};
    assert(Solution().change(5, input1) == 4);

    auto input2 = vector<int> {2};
    assert(Solution().change(3, input2) == 0);

    auto input3 = vector<int> {10};
    assert(Solution().change(10, input3) == 1);

    return 0;
}