#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/reverse-integer/
// 123 -> 321

// x = 123
// c = 123 % 10 = 3
// ans = 3

// x = 12 (123 / 10)
// c = 12 % 10 = 2

// if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && c > 7))
// if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && c > 8))
// ans = ans * 10 + c = 32

// ...
// ans = 321

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int c = x % 10;
            x /= 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX && c > 7)) return 0; // INT_MAX 2147483647
            if (ans < INT_MIN / 10 || (ans == INT_MIN && c > 8)) return 0; // INT_MIN -2147483648
            ans = ans * 10 + c;
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