#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/generate-parentheses

Solution1. Recursion / Backtracking
time: o(n)
space: o(n) depth
1. In recursion (give count of open and close, accumulated string)
1.1. Add accumulated string into answer list
1.2. if open < n: add open and call recursion. pop open
1.3. if open > close and close < n: add close and call recursion. pop open
*/

class Solution {
public:
    void backtracking(int n, int n_o, int n_c, string combi, vector<string>& ans) {
        if (n == n_o && n == n_c) {
            ans.push_back(combi);
        }
        else {
            if (n_o > n_c) backtracking(n, n_o, n_c + 1, combi+")", ans);
            if (n_o < n) backtracking(n, n_o + 1, n_c, combi+"(", ans);
        }
    }

    vector<string> generateParenthesis_1(int n) {
        vector<string> ans;
        backtracking(n, 0, 0, "", ans);
        return ans;
    }
    
    void recursion(vector<string>& res, int n, int o, int c, string& s) {
        if (o == n && c == n) {
            res.push_back(s);
            return;
        }
        
        if (o != n) {
            s += "(";
            recursion(res, n, o+1, c, s);
            s.pop_back();
        }
        if (o > c && c != n) {
            s += ")";
            recursion(res, n, o, c+1, s);
            s.pop_back();
        } 
    }
    vector<string> generateParenthesis_2(int n) {
        vector<string> res;
        string s;
        recursion(res, n, 0, 0, s);
        return res;
    }

    vector<string> generateParenthesis(int n) {
        return generateParenthesis_2(n);
    }
};

int main()
{
    assert(Solution().generateParenthesis(3)
        == (vector<string> {"((()))", "(()())", "(())()", "()(())", "()()()"}));
    return 0;
}
