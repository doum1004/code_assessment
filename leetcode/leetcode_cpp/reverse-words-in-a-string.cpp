#include <iostream>
#include <cassert>

#include <sstream>

using namespace std;

/**
https://leetcode.com/problems/reverse-words-in-a-string

// Solution1. iterate from begin to end
//time: o(n).
//space: o(n)

//Solution2. istringstream
//time: o(n)
//space: o(n)

//Solution3. in place solution
//time: o(n)
//space: o(1)

1. erase spaces between words
2. reverse words. and add space
3. reverse all string

*/

class Solution {
public:
    string reverseWords_iterate(string& s) {
        string res, str;
        for (auto &c:s) {
            if (isspace(c)) {
                if (!str.empty()) res = str + " " + res;
                str = "";
            }
            else {
                str += c;
            }
        }
        
        if (!str.empty()) res = str + " " + res;
        if (!res.empty()) res.pop_back();
        return res;
    }
    
    string reverseWords_istringstream(string& s) {
        if (s.empty()) return s;
        
        istringstream iss(s);
        string res, str;
        while (iss >> str)
            res = str + " " + res;
        
        if (res.size() > 0) res.pop_back();
        return res;
    }
    
    string reverseWords_inplace(string& s) {
        int l = 0, r = 0;
        while (r<s.size()) {
            while (r<s.size() && isspace(s[r])) r++;
            if (l != r) s.erase(l, r-l);
            r = l;
            if (r>=s.size()) break;
            
            while (r<s.size() && !isspace(s[r])) r++;
            if (l != r) reverse(s.begin()+l, s.begin()+r);
            l = r+1;
        }
        if (!s.empty() && isspace(s[s.size() - 1])) s.pop_back();
        reverse(s.begin(), s.end());
        return s;
    }

    string reverseWords_1(string& s) {
        string res;
        string word;
        for (int i=0; i<=s.size(); ++i) {
            if (i == s.size() || isspace(s[i])) {
                if (word.empty()) continue;

                if (res.empty()) res = word;
                else res = word + " " + res;
                word = "";
            } else {
                word += s[i];
            }
        }
        return res;
    }

    string reverseWords_3_1(string& s) {
        int n=s.size();
        int l=n, r=n;
        while (l >= 0) {
            while (r > 0 && isspace(s[r-1])) r--;
            l = r-1;
            while (l > 0 && !isspace(s[l-1])) l--;
            if (l < 0) break;

            if (s.size() != n)
                s += " ";
            s += s.substr(l, r-l);

            r = l-1;
        }
        s.erase(s.begin(), s.begin()+n);
        return s;
    }

    string reverseWords_3(string& s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int i = 0, l = 0, r = 0;
        while (i < n) {
            while (i < n && s[i] == ' ')
                s[r++] = s[i++];

            if (l < r) {
                reverse(s.begin()+l, s.end()+r);
                s[r++] = ' ';
                l = r;
            }
            i++;
        }
        while (r > 0 && s[r-1] == ' ') r--;
        s.resize(r);
        return s;
    }
    
    string reverseWords(string s) {
        //return reverseWords_iterate(s);
        //return reverseWords_istringstream(s);
        return reverseWords_3(s);
    }
};

int main()
{
    assert(Solution().reverseWords("  e f  g  ") == ("g f e"));
    assert(Solution().reverseWords("the sky is blue") == ("blue is sky the"));
    return 0;
}
