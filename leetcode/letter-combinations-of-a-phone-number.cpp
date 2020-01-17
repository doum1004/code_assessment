#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// backtracking to find all possibility 
// o(3N x 4M)
// o(3N x 4M)
// map
// [2] = vector<char> {'a', 'b', 'c'}
// [3] = vector<char> ...
// vector<strig> ans;
// backtrack(map, str, digits)
//  if (digits == "") ans.push_back(str);
//  else
//      cur = digits.substr(0,1)
//      if (map.find(cur))
//          for (auto& c:map[cur])
//              backtrack(map, str + c, digits.substr(1))
//  
//
// back(map, "", digits)

class Solution {
private:
    vector<string> ans;
    void letterCombinations(unordered_map<string, string>& map, string combi, string digits) {
        if (digits == "") {
            ans.push_back(combi);
        }
        else {
            auto cur = digits.substr(0, 1);
            if (map.find(cur) != map.end()) {
                for (auto& c : map[cur]) {
                    letterCombinations(map, combi + c, digits.substr(1));
                }
            }
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        auto phone = unordered_map<string, string>();
        phone["2"] = "abc";
        phone["3"] = "def";
        phone["4"] = "ghi";
        phone["5"] = "jkl";
        phone["6"] = "mno";
        phone["7"] = "pqrs";
        phone["8"] = "tuv";
        phone["9"] = "wxyz";
        if (digits != "")
            letterCombinations(phone, "", digits);
        return ans;
    }
};

int main()
{
    assert(Solution().letterCombinations("23")
        == (vector<string> {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
    return 0;
}