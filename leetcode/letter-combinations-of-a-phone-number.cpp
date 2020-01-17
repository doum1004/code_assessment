#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:

// Although the above answer is in lexicographical order, your answer could be in any order you want.

class Solution {
public:
    void backtracking(unordered_map<string, string> &phone, vector<string> &output, string combination, string next_digits) {
        if (next_digits == "")
        {
            output.push_back(combination);
        }
        else
        {
            auto cur_digit = next_digits.substr(0,1);
            if (phone.find(cur_digit) != phone.end()) {
                auto chars = phone[cur_digit];
                for (auto &c : chars) {
                    backtracking(phone, output, combination + c, next_digits.substr(1));
                }
            }
        }
    }

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
        
        vector<string> ans;
        if (digits != "")
            backtracking(phone, ans, "", digits);
        return ans;
    }
};

int main()
{
    assert(Solution().letterCombinations("23")
        == (vector<string> {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
    return 0;
}