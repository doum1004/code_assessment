#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

// https://leetcode.com/problems/roman-to-integer/

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

class Solution {
public:
    int romanToInt(string s) {
        // arrays for values, symbols
        // time: o(n)
        // space: o(1)

        int values[] =      {1000,  900,    500,    400,    100,    90,     50,     40,     10,     9,      5,      4,      1};
        string symbols[] =  {"M",   "CM",   "D",    "CD",   "C",    "XC",   "L",    "XL",   "X",    "IX",   "V",    "IV",   "I"};

        auto ans = 0;
        auto j = 0;
        for (int i=0; i<13; ++i) {
            auto size = symbols[i].size();
            while (j < (int)s.size() && symbols[i] == s.substr(j, size)) {
                j += size;
                ans += values[i];
            }
        }

        return ans;
    }
};
 
int main()
{
    assert(Solution().romanToInt("III") == 3); 
    assert(Solution().romanToInt("IV") == 4); 
    assert(Solution().romanToInt("IX") == 9);
    assert(Solution().romanToInt("LVIII") == 58);
    assert(Solution().romanToInt("MCMXCIV") == 1994);
    assert(Solution().romanToInt("MMMXLV") == 3045); 
    return 1;
}