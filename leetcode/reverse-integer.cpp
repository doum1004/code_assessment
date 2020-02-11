#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/reverse-integer/

// solution1. pop and push digits & check overflow
// time: o(log(n)) : log10(n) = n number of digit place
// space: o(1)

123 % 10 = 3 3
12 % 10 = 2  32
1 & 10 = 1   321

1. loop till input goes 0
2. get mode of first digit
2. remove first digit in input
3. check the overflow
4. add the mode in ans

int ans = 0;
while (x!=0)
    int c = x % 10;
    x /= 10;
    if (ans > INT_MAX/10 || (ans == INT_MAX/10 && c>7)) return 0
    if (ans < INT_MIN/10 || (ans == INT_MIN/10 && c>8)) return 0
    ans = c + ans*10;

*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x!=0) {
            int c = x%10;
            x /= 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX && c > 7)) return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN && c > 8)) return 0;
            ans = ans*10 + c;
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