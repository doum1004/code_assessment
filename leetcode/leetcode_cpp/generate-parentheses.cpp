#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/generate-parentheses/solution/

// backtraking
// time: o(4^n/squre(n))  ?????
// space: o(4^n/squre(n)) + o(n)

// The way I like to think about the runtime of backtracking algorithms is O(b^d), where b is the branching factor and d is the maximum depth of recursion. ... WTF

n = 3
o = 3
c = 3
open
o < n
close
c < o

n = 1
()

n = 2
()()
(())

vector<string> ans;
generate(int n, str result, int n_o, int n_c)
    if (n_o == n && n_c == n) {
        ans.push_back(result);
    }
    else {
        if (n_o < n)
            generate(n, result + "(", n_o + 1, n_c);
        if (n_c < n_o)
            generate(n, result + ")", n_o, n_c + 1);
    }
    
    
generate(n, "", 0, 0)
return ans;
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
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking(n, 0, 0, "", ans);
        return ans;
    }
};

int main()
{
    assert(Solution().generateParenthesis(3)
        == (vector<string> {"((()))", "(()())", "(())()", "()(())", "()()()"}));
    return 0;
}
