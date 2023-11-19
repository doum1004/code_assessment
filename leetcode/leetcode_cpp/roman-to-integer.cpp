#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

// https://leetcode.com/problems/roman-to-integer/

// iterate stores to subtract data
// time: o(n) : number of romans table * max(1,3)
// space: o(n) : number of romans in table
//
// l = 0
// iterate vector (romans)
// roman : romans
//  while (s.substr(l, roman.first.size()) == roman.first)
//      l += roman.first.size()
//      ans += roman.second;

class Solution {
public:
    int romanToInt_1(string& s) {
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
        
        int ans = 0;
        int l = 0;
        for (auto &roman : romans) {
            while (s.substr(l, roman.first.size()) == roman.first) {
                l += roman.first.size();
                ans += roman.second;
            }
        }
        return ans;
    }

    int romanToInt_2(string& s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int res = 0;
        for (int i=0; i<s.size(); ++i) {
            if (i + 1 < s.size() && m[s[i]] < m[s[i + 1]])
                res -= m[s[i]];
            else
                res += m[s[i]];
        }
        return res;
    }
    
    int romanToInt(string s) {
        return romanToInt_2(s)
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