#include <iostream>
#include <cassert>

#include <stack>

using namespace std;

/**
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

// Solution1. Using Stack to check invalid parentheses
// time: o(n)
// space: o(n)

ex, )(a(b(c)d)
i=0, stack:         s = (a(b(c)d). erase ')'
i=1, stack: (       s = (a(b(c)d)
i=3, stack: ((      s = (a(b(c)d)
i=5, stack: (((     s = (a(b(c)d)
i=7, stack: ((      s = (a(b(c)d)
i=9, stack: (       s = (a(b(c)d)
erase '('           s = a(b(c)d)


// Solution2. no extra space
// time: o(n). 2n
// space: o(1)
iterate from end to begin, to shift only valid char to right
iterate from begin to end, to shift only valid char to left

*/

class Solution {
public:
    string minRemoveToMakeValid_bruteforce(string& s) {
        stack<int> st;
        for (int i=0; i<s.size(); ++i) {
            auto &c=s[i];
            if (c == ')') {
                if (!st.empty() && c != s[st.top()]) {
                    st.pop();
                }
                else {
                   s[i] = '*';
                }
            }
            else if (c == '(') {
                st.push(i);
            }
        }
        
        while (!st.empty()) {
            //s.erase(st.top(),1);
            s[st.top()] = '*';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        
        return s;
    }
    
    string minRemoveToMakeValid_nospace(string& s) {
        int balance = 0;
        int r = s.size();
        for (int i=s.size()-1; i>=0; --i) {
            if (s[i] == ')') balance++;
            else if (s[i] == '(') {
                if (balance == 0) continue;
                balance--;
            }
            s[--r] = s[i];
        }
        
        balance = 0;
        int l = 0;
        for (; r<s.size(); ++r) {
            if (s[r] == '(') balance++;
            else if (s[r] == ')') {
                if (balance == 0) continue;
                balance--;
            }
            s[l++] = s[r];
        }
        s.erase(l);
        return s;
    }
    
    string minRemoveToMakeValid(string s) {
        //return minRemoveToMakeValid_bruteforce(s);
        return minRemoveToMakeValid_nospace(s);
    }
};

int main()
{
    assert(Solution().minRemoveToMakeValid("lee(t(c)o)de)") == "lee(t(c)o)de");
    assert(Solution().minRemoveToMakeValid("a)b(c)d") == "ab(c)d");
    assert(Solution().minRemoveToMakeValid("))((") == "");
    assert(Solution().minRemoveToMakeValid("(a(b(c)d)") == "a(b(c)d)");
    return 0;
}