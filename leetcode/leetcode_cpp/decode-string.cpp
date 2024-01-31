#include <iostream>
#include <cassert>

#include <stack>
#include <math.h>

using namespace std;

/**
https://leetcode.com/problems/decode-string/

// solution1. iteration with stack
// time: o(n) : 2n
// space: o(n)
1. iterate car in string
2. in case of char is not ']', add char in stack
3. in case of char is ']', pop stack to find str, and int. and decode it
3.1 if stack is not empty, then put string in stack again for later decoding
3.2 otherwise, add it in result.
4. when iteration done, check data in stack to accumulate value in final result

// solution2. recursion
// time: o(n)
// space: o(m) max of brackets (inner)
1. recursive string s, idx
2. iterate till idx < s.size && s[idx] == ']'
3. in iteration, if s[idx] none digit accumulate str
4.               else get number and recursion call again with get the string and decoded string with number

3[a]2[bc]
r(3[a]2[bc], 0)
    r(3[a]2[bc], 2) -> a
    aaa
 
    r(3[a]2[bc], 4) -> bc
    bcbc

3[a2[c]]
r(3[a2[c]], 0)
    r(3[a2[c]], 2) -> acc
        r(3[a2[c]], 5) -> c
        cc
    accaccacc
 
 
3. Iterate and store str and num in list(stack) for later operation
time: o(n)
space: o(n)
1. digit: curNum = n*10 + c-'0'
2. alpha: curStr += c
3. '[': store curNum and curStr into list (nums, strs)
4. ']': store last 'nums' * curStr into last 'strs' list. st = strs[-] and pop both list

*/

class Solution {
private:
    string decode(string &s, int num) {
        string decoded{};
        for (int i=1; i<=num; ++i) {
            decoded += s;
        }
        return decoded;
    }
    
public:
    string decodeString_stack(string &s) {
        stack<char> stack_char;
        
        string decoded{};
        for (auto &c:s) {
            if (c == ']') {
                // find str
                string str{};
                while (!stack_char.empty() && stack_char.top() != '[') {
                    str = stack_char.top() + str;
                    stack_char.pop();
                }
                stack_char.pop(); //[
                
                // find n
                int n = 0;
                int place = 0;
                while (!stack_char.empty() && isdigit(stack_char.top())) {
                    n += pow(10, place++) * (stack_char.top() - '0');
                    stack_char.pop();
                }
                
                str = decode(str, n);
                if (stack_char.empty()) decoded += str;
                else {
                    for (auto &dc:str) {
                        stack_char.push(dc);
                    }
                }
            }
            else {
                stack_char.push(c);
            }
        }
        
        string str = "";
        while (!stack_char.empty()) {
            str = stack_char.top() + str;
            stack_char.pop(); //pop char
        }
        
        return decoded + str;
    }
    
    string decodeString_recursion(string &s, int &i) {
        string str;
        while (i<s.size() && s[i] != ']') {
            if (!isdigit(s[i])) {
                str += s[i++];
            }    
            else {
                int n=0;
                while (isdigit(s[i])) {
                    n = n*10 + (s[i++] - '0');
                }
                i++; //[
                auto toDecode = decodeString_recursion(s, i);
                i++; //]
                while (n-->0) {
                    str += toDecode;
                }
            }
        }
        
        return str;
    }
    
    string decodeString_recursion(string &s) {
        int i{};
        return decodeString_recursion(s,i);
    }
    
    string decodeString_3(string s) {
        vector<string> strs;
        vector<int> nums;
        int n = 0;
        string st;
        for (auto c : s) {
            if (c == '[') {
                strs.push_back(st);
                nums.push_back(n);
                st = "";
                n = 0;
            }
            else if (c == ']') {
                for (int i=1; i<=nums.back(); ++i)
                    strs.back() += st;

                st = strs.back(); 
                strs.pop_back();
                nums.pop_back();
            }
            else if (isdigit(c)) {
                n = c - '0' + n * 10;
            }
            else {
                st += c;
            }
        }
        return st;
    }

    string decodeString(string s) {
        //return decodeString_stack(s);
        //return decodeString_recursion(s);
        return decodeString_3(s);
    }
};

int main()
{
    assert(Solution().decodeString("3[a]2[bc]")
        == "aaabcbc");

    return 0;
}