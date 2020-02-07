#include <iostream>
#include <cassert>

#include <stack>
#include <math.h>

using namespace std;

/**
https://leetcode.com/problems/decode-string/

// solution1. using stack to accumulate nums
// time: o(n)
// space: o(n)
1. detect num and deconding input
using stack. once hits ] than pop to get str and numerber after
2. deconding function
decoding with str and num
3. if stack is empty than return, otherwise put them back into stack

// solution2. recursive without stack
// time: o(n)
// space: o(m) recursion: number of set of brackets

recursive(&s, &i) {
    // return string in [] or out
    
    string str;
    while (i < s.size() && s[i] == ']') {
        if (!isdigit(s[i])) {
            str += s[i]; // get inner str
        }
        else {
            // encoding process
            int n = 0;
            while (isdigit(s[i])) {
                n = n * 10 + (s[i] - '0');
                i++;
            }
            i++ // [
            auto toDecode = recursive(s, i); // get inner str
            i++ // ]
            while (n-- > 0) {
                str += toDecode; // decoded result
            }
        }
    }
    
    return str;
}

*/

class Solution {
public:
    string deconding(string &s, int n) {
        string deconded;
        for (int i=0; i<n; ++i) {
            deconded += s; 
        }
        return deconded;
    }
    
    string decodeString_stack(string &input) {
        string ans = "";
        
        stack<char> s;
        for (int i=0; i<input.size(); ++i) {
            auto c = input[i];
            if (c == ']') {
                string str;
                while (s.top() != '[') {
                    str = s.top() + str;
                    s.pop(); //pop char
                }
                s.pop(); //pop [
                cout << str << endl;

                int n = 0;
                int place = 0;
                while (!s.empty() && isdigit(s.top())) {
                    int d = (s.top() - '0') * pow(10, place++);
                    n += d;
                    s.pop(); //pop num
                }
                cout << n << endl;

                auto decoded = deconding(str, n);
                cout << decoded << endl;
                if (s.empty()) {
                    ans += decoded;
                }
                else {
                    for (auto &dc:decoded) {
                        s.push(dc);
                    }
                }
            }
            else {
                s.push(c);
            }
        }
        
        string str = "";
        while (!s.empty()) {
            str = s.top() + str;
            s.pop(); //pop char
        }

        return ans + str;
    }
    
    string decodeString_recursive(string &s, int &i) {
        string str;
        while (i < s.size() && s[i] != ']') {
            if (!isdigit(s[i])) {
                str += s[i++];
            }
            else {
                int n = 0;
                while (isdigit(s[i])) {
                    n = n * 10 + (s[i++] - '0');
                }
                i++; // [
                auto toDecode = decodeString_recursive(s, i);
                i++; // ]
                while (n-- > 0) {
                    str += toDecode;
                }
            }
        }

        return str;
    }
    
    string decodeString_recursive(string s) {
        int i=0;
        return decodeString_recursive(s, i);
    }
    
    string decodeString(string s) {
        //return decodeString_stack(s);
        return decodeString_recursive(s);
    }
};

int main()
{
    assert(Solution().decodeString("3[a]2[bc]")
        == "aaabcbc");

    return 0;
}