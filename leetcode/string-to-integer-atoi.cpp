#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str) {
        // visit str and store
        // time: o(n)
        // space: o(1)

        int ans = 0;
        bool neg = false;
        bool digit_flag = false;
        bool neg_falg = false;

        for (auto c : str) {
            if (isspace(c))
            {
                if (digit_flag || neg_falg) break;
            }
            else if (isdigit(c))
            {
                digit_flag = true;
                auto n = c - '0';
                if ((ans < INT_MIN / 10) || ((ans == INT_MIN / 10) && ((!neg) ? n > 7 : n > 8))) {
                    return (!neg) ? INT_MAX : INT_MIN;
                }
                ans = ans * 10 - n;
            }
            else if (c == '-' || c == '+')
            {
                if (digit_flag || neg_falg) break;
                neg_falg = true;

                if (c == '-') neg = !neg;
            }
            else
            {
                break;
            }
            
        }

        return (!neg) ? ans * -1 : ans;
    }
};

int main()
{
    assert(Solution().myAtoi("42") == 42);
    assert(Solution().myAtoi("   -42") == -42);
    assert(Solution().myAtoi("4193 with words") == 4193);
    assert(Solution().myAtoi("words and 987") == 0);
    assert(Solution().myAtoi("-91283472332") == -2147483648);
    assert(Solution().myAtoi("+-2") == 0);
    assert(Solution().myAtoi("   +0 123") == 0);
    assert(Solution().myAtoi("-2147483648") == -2147483648);
    return 0;
}