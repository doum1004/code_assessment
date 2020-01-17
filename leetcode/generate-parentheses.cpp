#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

class Solution {
public:

    vector<string> generateParenthesis_bruteforce(int n) {
        return vector<string>();
    }

    void generateParenthesis_backtracking(vector<string> &ans, string parenthessis, int open, int close, int n) {
        if (parenthessis.size() == n * 2)
        {
            ans.push_back(parenthessis);
            return;
        }
        
        if (open < n)
            generateParenthesis_backtracking(ans, parenthessis + "(", open + 1, close, n);
        if (close < open)
            generateParenthesis_backtracking(ans, parenthessis + ")", open, close + 1, n);
    }

    vector<string> generateParenthesis_backtracking(int n) {
        vector<string> ans;
        generateParenthesis_backtracking(ans, "", 0, 0, n);
        return ans;
    }

    vector<string> generateParenthesis(int n) {
        return generateParenthesis_backtracking(n);
    }
};

int main()
{
    assert(Solution().generateParenthesis(3)
        == (vector<string> {"((()))", "(()())", "(())()", "()(())", "()()()"}));
    return 0;
}