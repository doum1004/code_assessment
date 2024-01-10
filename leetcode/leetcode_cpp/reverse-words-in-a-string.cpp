#include <iostream>
#include <cassert>

#include <sstream>

using namespace std;

/**
https://leetcode.com/problems/reverse-words-in-a-string

Solution1. iterate from begin to end
time: o(n).
space: o(n)

Solution2_1. reverse words with erase
time: o(n)
space: o(1)

1. erase spaces between words
2. reverse words. and add space
3. reverse all string

Solution2_2. reverse words with resize
time: o(n)
space: o(1)

1. 
2. reverse words. and add space
3. reverse all string
*/

class Solution {
public:
    string reverseWords_1(string& s) {
        string res;
        string word;
        for (int i=0; i<=s.size(); ++i) {
            if (i == s.size() || isspace(s[i])) {
                if (!word.empty()) res = word + " " + res;
                word = "";
            }
            else {
                word += s[i];
            }
            
        }
        if (res.size()) res.pop_back();
        return res;
    }

    string reverseWords_2_1(string& s) {
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

    string reverseWords_2_2(string& s) {
        reverse(s.begin(), s.end());
        int l=0, r=0, n=s.size(), lastIdx = 0;
        while (r<n) {
            while (r<n && s[r] == ' ') r++;
            int startIdx = l;
            while (r<n && s[r] != ' ') {
                s[l++] = s[r++];
                lastIdx = l;
            }
            reverse(s.begin() + startIdx, s.begin() + lastIdx);
            s[l++] = ' ';
        }
        s.resize(lastIdx);
        return s;
    }

    string reverseWords(string s) {
        return reverseWords_2_2(s);
    }
};

int main()
{
    assert(Solution().reverseWords("  e f  g  ") == ("g f e"));
    assert(Solution().reverseWords("the sky is blue") == ("blue is sky the"));
    return 0;
}
