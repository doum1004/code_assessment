#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
solution1. iteration
o(N*4^N) / o(N*4*N)

solution2. recursion (backtracking of all possibilities)
o(N*4^N) / o(N*4*N)

*/

class Solution {
public:
    vector<string> letterCombinations_iterate(unordered_map<char, vector<char>> &m, string &digits) {
        // interate string and interate res vector to resotre new
        // o(n*4^2)
        vector<string> res;
        for (auto d:digits) {
            vector<string> update;
            for (auto item:m[d]) {
                if (res.size() > 0) {
                    for (auto pre:res) {
                        update.push_back(pre + item);
                    }
                }
                else {
                    update.push_back(string(1,item));
                }
            }  
            res = update;
        }
        return res;
    }
        
    void letterCombinations_recursive_backtrack(unordered_map<char, vector<char>> &m, string store, string digits, vector<string> &ans) {
        if (digits.empty()) {
            if (!store.empty()) ans.push_back(store);
        }
        else {
            for (auto &c:m[digits[0]]) {
                letterCombinations_recursive_backtrack(m, store + c, digits.substr(1), ans);
            }
        }
    }
        
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> m;
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        
        //return letterCombinations_iterate(m, digits);
        vector<string> ans;
        letterCombinations_recursive_backtrack(m, "", digits, ans);
        return ans;
    }
};

int main()
{
    assert(Solution().letterCombinations("23")
        == (vector<string> {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
    return 0;
}
