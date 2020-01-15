#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
string intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    string ans = "";
    for (int i = 0; i < 13; i++)
    {
        while (num - values[i] >= 0)
        {
            ans += symbols[i];
            num -= values[i];
        }
    }

    return ans;
}

int main()
{
    assert(intToRoman(3) == "III");
    assert(intToRoman(4) == "IV");
    assert(intToRoman(9) == "IX");
    assert(intToRoman(58) == "LVIII");
    assert(intToRoman(1994) == "MCMXCIV");
    return 0;
}