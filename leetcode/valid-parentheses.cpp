#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

// https://leetcode.com/problems/valid-parentheses/

// iterate and count nuber of open and wait for expected close

// ()
// i        s: )
//  i

// ()[]
// i        s: )
//  i       s:
//   i      s: [
//    i .   s:

// ([)]
// s: ),  s: )] 

class Solution {
public:
    bool isValid(string s) {
        stack<char> expects;
        for (auto &c : s) {
            if (c == '(') expects.push(')');
            else if (c == '{') expects.push('}');
            else if (c == '[') expects.push(']');
            else if (c == ')' || c == '}' || c == ']') {
                if (expects.size() < 1) return false;
                auto expect = expects.top();
                expects.pop();
                if (expect != c) return false;
            }
        }
        
        return expects.size() == 0;
    }
};

int main()
{
    assert(Solution().isValid("()")
        == true);
    return 0;
}