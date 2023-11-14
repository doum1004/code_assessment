#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>
#include <map>

using namespace std;

/*

https://leetcode.com/problems/valid-parentheses/

sol1. stack (filo better than vector. no resizing) 
time: o(n)
space: o(n)

()
v = 

()[]{}

(]

*/

class Solution {
public:
    bool isValid(string s) {
        std::map<char, char> m;
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';

        stack<char> st;
        for (auto c : s) {
            if (m.find(c) != m.end()) {
                if (!st.size() || st.top() != m[c])
                    return false;
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.size() == 0;
    }
};

int main()
{
    assert(Solution().isValid("()")
        == true);
    return 0;
}