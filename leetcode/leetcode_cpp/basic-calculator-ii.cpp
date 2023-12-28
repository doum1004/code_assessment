#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/basic-calculator-ii

// Solution1. Put result on stack
// time: o(n)
// space: o(n)

ex) 3+2*2
sign '+'. stack: 3
sign '+'. stack: 3,2
sign '*'. stack: 3,4(2*2)
res = 3+4

ex) 13-4*2
sign '+'. stack:13
sign '-'. stack:13,-4
sign '*'. stack:13,-8(-4*2)
res = 13-8

// Solution2. Calculate without stack
// time: o(n)
// space: o(1)

ex) 3+2*2
start from this init. sign +, num=3 from nextNum
'+' -> total += num * sign. num=nextNum. sign=+
total=3, num=2. sign=+

'*' -> num = num * nextNum
num=2*2=4

after iteration
total += num * sign = 7

ex) 12-4*2
init: sign+, num=12.
- -> total=12. num=4 sign=-
* -> num=4*2=8

after iteration
total += num*sign = 4

*/


class Solution {
public:
    int calculate_stack(string &s) {
        stack<int> cals;
        char sign = '+';
        int num = 0;
        for (int i=0; i<s.size(); ++i) {
            if (isdigit(s[i])) {
                num = num*10 + (s[i] - '0');
            }
            
            if ((!isdigit(s[i]) && !isspace(s[i])) || i == s.size() - 1) {
                if (sign == '+') {
                    cals.push(num);
                }
                else if (sign == '-') {
                    cals.push(num * -1);
                }
                else {
                    auto pre = cals.top();
                    cals.pop();
                    
                    if (sign == '*') {
                        pre *= num;
                    }
                    else if (sign == '/') {
                        pre /= num;
                    }
                    
                    cals.push(pre);
                } 
                sign = s[i];
                num = 0;
            }
        }
        
        int res = 0;
        while (!cals.empty()) {
            auto n = cals.top();
            cals.pop();
            res+=n;
        }
        return res;
    }
    
    int calculate_nostack(string& s) {
        int i=0;
        int total = 0, num = getNext(s, i), sign = 1; // sign(1:+, -1:-)
        while (i<s.size()) {
            if (s[i] == '+') {
                total += num * sign;
                sign = 1;
                num = getNext(s, ++i);
            }
            else if (s[i] == '-') {
                total += num * sign;
                sign = -1;
                num = getNext(s, ++i);
            }
            else if (s[i] == '*') {
                num *= getNext(s, ++i);
            }
            else if (s[i] == '/') {
                num /= getNext(s, ++i);
            }
        }
        
        total += num * sign;
        return total;
    }
    
    int calculate(string s) {
        //return calculate_stack(s);
        return calculate_nostack(s);
    }
    
private:
    int getNext(string &s, int &i) {
        int n = 0;
        for (;i<s.size();++i) {
            if (isspace(s[i])) continue;
            if (!isdigit(s[i])) break;
            n = n * 10 + (s[i] - '0');
        }
        return n;
    }
};

int main()
{
    assert(Solution().calculate("3+2*2") == (7));
    assert(Solution().calculate(" 3/2 ") == (1));
    assert(Solution().calculate(" 3+5 / 2 ") == (5));
    assert(Solution().calculate(" 13-4 * 2 ") == (5));

    return 0;
}
