#include <iostream>
#include <vector>
#include <cassert>
#include "../../utils.h"

using namespace std;

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
int romanToInt(string s) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int ans = 0;
    auto l = 0;
    for (int i = 0; i < 13; i++)
    {
        auto size = symbols[i].size();
        while (l < s.size() && symbols[i] == s.substr(l, size))
        {
            l += size;
            ans += values[i];
        }
    }

    return ans;
}

int main()
{
    assert(romanToInt("III") == 3);
    assert(romanToInt("IV") == 4);
    assert(romanToInt("IX") == 9);
    assert(romanToInt("LVIII") == 58);
    assert(romanToInt("MCMXCIV") == 1994);
    assert(romanToInt("MMMXLV") == 3045);
    return 0;
}