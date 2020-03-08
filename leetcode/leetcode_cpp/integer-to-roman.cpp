#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/integer-to-roman/

// subtract maximum possibility
// o(n) : roman mapper(13 * max(4))
// o(n) : map(roman mapper)

// map<int, pair<string, int>>
// [0] = {M, 1000}
// [1] = {CM, 900}

// ans = ""
// for (i in map.size()-1)
//  while (num - map[i].second > 0)
//      ans += map[i].first
//      n -= map[i].second
// return ans


class Solution {
public:
    string intToRoman1(int num) {
        vector<pair<string, int>> romans;
        romans.push_back({"M", 1000});
        romans.push_back({"CM", 900});
        romans.push_back({"D", 500});
        romans.push_back({"CD", 400});
        romans.push_back({"C", 100});
        romans.push_back({"XC", 90});
        romans.push_back({"L", 50});
        romans.push_back({"XL", 40});
        romans.push_back({"X", 10});
        romans.push_back({"IX", 9});
        romans.push_back({"V", 5});
        romans.push_back({"IV", 4});
        romans.push_back({"I", 1});
        
        string ans = "";
        for (auto v : romans) {
            while (num - v.second >= 0) {
                ans += v.first;
                num -= v.second;
            }
        }
        return ans;
    }

    string intToRoman2(int num) {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string res;
        for (int i=0; i<nums.size(); ++i) {
            auto c = num / nums[i];
            if (c > 0) {
                for (auto j=1; j<=c; ++j) {
                    res += symbols[i];
                }
            }
            num %= nums[i];
        }
            
        return res;
    }

    string intToRoman(int num) {
        //return intToRoman1(num);
        return intToRoman2(num);
    }
};

int main()
{
    assert(Solution().intToRoman(3) == "III");
    assert(Solution().intToRoman(4) == "IV");
    assert(Solution().intToRoman(9) == "IX");
    assert(Solution().intToRoman(58) == "LVIII");
    assert(Solution().intToRoman(1994) == "MCMXCIV");
    return 0;
}