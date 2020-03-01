#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/string-to-integer-atoi/

// Solution. Iterate string
// time o(n)
// space o(1)

// "42"  42
// "   -42"  -42
// skip empty
// first none num should be + or -
// char after num ends
// limit for int

// ans = 0
// neg = false
// firstNoneWhiteSpace = false
// iterate c: str
//  if (isspace(c))
//      continue
//  else
//      if (isdigit())
//          auto digit = c - '0'
//          if (!neg && (ans < INT_MIN / 10) || (ans == INT_MIN / 10) digit>7) return INT_MAX;
//          if (neg && (ans < INT_MIN / 10) || (ans == INT_MIN / 10) digit>8) return INT_MIN;
//          ans = ans * 10 - digit
//      else
//          if (firstNoneWhiteSpace) break;
//          if (c == "-" || c == "+") neg = c == "-"
//          else break;
//          
//      firstNoneWhiteSpace = true
//  

class Solution {
public:
    int myAtoi(string str) {
        if (str.size() < 1) return 0;
        int n = str.size();
        int ans = 0;
        bool neg = false;
        bool firstNoneWhiteSpace = false;
        
        for (auto &c : str) {
            if (isspace(c)) {
                if (firstNoneWhiteSpace) break;
            }
            else {
                if (isdigit(c)) {
                    auto digit = c - '0';
                    if (!neg && (ans < INT_MIN / 10 || ((ans == INT_MIN / 10) && digit > 7))) return INT_MAX;
                    if (neg && (ans < INT_MIN / 10 || ((ans == INT_MIN / 10) && digit > 8))) return INT_MIN;
                    ans = ans * 10 - digit; // negative holds more !!!!
                }
                else {
                    if (firstNoneWhiteSpace) break;
                    if (c == '-' || c == '+') neg = c == '-';
                    else break;
                }
                firstNoneWhiteSpace = true;
            }
        }
        
        return (neg) ? ans : ans * -1;
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