#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number
solution1. iteration
o(N*4^N) / o(N*4*N)

solution2. recursion (backtracking of all possibilities)
Backtracking is a general algorithm for finding all (or some) solutions to a computational problem (particularly those that incrementally build candidates for a solution).
It's often used when a problem can be broken down into a set of choices, and the algorithm systematically explores each possibility until it finds a solution or exhausts all options.

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
        
    vector<string> letterCombinations_2(string digits) {
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

    void backtracking(unordered_map<int, string>& m, string& digits, string& cur, int i, vector<string>& res) {
        if (i == digits.size()) {
            if (cur != "") res.push_back(cur);
            return;
        }

        for (auto c : m[digits[i]]) {
            cur.push_back(c);
            backtracking(m, digits, cur, i + 1, res);
            cur.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        string s = "";
        vector<string> res;
        backtracking(m, digits, s, 0, res);
        return res;
    }
};

int main()
{
    assert(Solution().letterCombinations("23")
        == (vector<string> {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
    return 0;
}
