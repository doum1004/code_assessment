#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/generate-parentheses/

// n = 1
// o=0 c=0
// (
// o=1 c=0
// ()
// o=1 c=1
// 

// n = 2
// o=0
// (
// o=1
// o
// (()), ()()

// tiem: O(b^d), backtracking algorithms where b is the branching factor and d is the maximum depth of recursion.
// Backtracking is characterized by a number of decisions b that can be made at each level of recursion. If you visualize the recursion tree, this is the number of children each internal node has. You can also think of b as standing for "base", which can help you remember that b is the base of the exponential.
// If we can make b decisions at each level of recursion, and we expand the recursion tree to d levels (ie: each path has a length of d), then we get b^d nodes. Since backtracking is exhaustive and must visit each one of these nodes, the runtime is O(b^d).

class Solution {
public:
    vector<string> ans;
    void generateParenthesis(string s, int n, int o, int c) {
        if (n == o && n == c)
        {
            ans.push_back(s);
            return;
        }
        
        if (o < n) generateParenthesis(s + "(", n, o + 1, c);
        if (c < o) generateParenthesis(s + ")", n, o, c + 1);
    }
    
    vector<string> generateParenthesis(int n) {
        generateParenthesis("", n, 0, 0);
        return ans;
    }
};

int main()
{
    assert(Solution().generateParenthesis(3)
        == (vector<string> {"((()))", "(()())", "(())()", "()(())", "()()()"}));
    return 0;
}