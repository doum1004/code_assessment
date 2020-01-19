#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            
            if (ans > INT_MAX / 10 || (ans == INT_MAX && pop == 7)) return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN && pop == -8)) return 0;
            ans = ans * 10 + pop;
        }

        return ans;
    }
};

int main()
{
    assert(Solution().reverse(123) == 321);
    assert(Solution().reverse(-123) == -321);
    assert(Solution().reverse(120) == 21);
    assert(Solution().reverse(-10) == -1);
    assert(Solution().reverse(10) == 1);
    assert(Solution().reverse(INT_MIN) == 0);
   
    return 0;
}