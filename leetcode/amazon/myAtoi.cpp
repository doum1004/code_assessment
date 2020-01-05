#include <iostream>
#include <vector>
#include <cassert>
#include "../../utils.h"

using namespace std;

int myAtoi(string str) {
    int ans = 0;
    bool neg = false;
    bool digit_flag = false;
    for (auto c : str)
    {
        if (isspace(c))
        {
            if (digit_flag)
                break;

            continue;
        }
        else if (isdigit(c))
        {
            digit_flag = true;
            auto digit = c - '0';
            if (neg && ans < (INT_MIN + digit) / 10)
            {
                return INT_MIN;
            }
            else if (!neg && -ans > (INT_MAX - digit) / 10)
            {
                return INT_MAX;
            }
            ans = ans * 10 - digit;
        }
        else if (c == '-' || c == '+')
        {
            if (digit_flag)
                break;

            digit_flag = true;
            if (c == '-')
                neg = true;
        }
        else
        {
            break;
        }
    }

    return neg ? ans : -ans;
}

int myAtoi2(string str) {
    auto map = unordered_map<char, int>();
    auto i = 0;
    for (auto c : "0123456789")
    {
        map[c] = i++;
    }
    auto assigned = false;
    auto sign = 1;
    unsigned long ans = 0;
    for (auto s : str)
    {
        if (map.find(s) != map.end())
        {
            assigned = true;
            ans *= 10;
            ans += map[s];
            if (ans > (INT_MAX))
            {
                if (sign > 0)
                {
                    return INT_MAX;
                }
                else
                {
                    return INT_MIN;
                }
            }
        }
        else
        {
            if (!assigned && (s == '+' || s == '-'))
            {
                assigned = true;
                if (s == '-')
                {
                    sign *= -1;
                }
            }
            else if (!assigned && s == ' ')
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }

    return ans * sign;
}

int main()
{
    assert(myAtoi("42") == 42);
    assert(myAtoi("   -42") == -42);
    assert(myAtoi("4193 with words") == 4193);
    assert(myAtoi("words and 987") == 0);
    assert(myAtoi("-91283472332") == -2147483648);
    assert(myAtoi("+-2") == 0);
    assert(myAtoi("   +0 123") == 0);
    assert(myAtoi("-2147483648") == -2147483648);
    return 0;
}