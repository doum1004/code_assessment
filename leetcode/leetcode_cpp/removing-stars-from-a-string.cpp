/*
https://leetcode.com/problems/removing-stars-from-a-string

1. iterate and push, pop on string
time: o(n)
space: o(n)

2. two pointers (actual place, iterate place) and resize(l)
time: o(n)
space: o(1)
*/

class Solution {
public:
    string removeStars_1(string& s) {
        string res;
        for (auto c : s) {
            if (c == '*') res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
    string removeStars_2(string& s) {
        int l = 0, r = 0;
        while (r < s.size()) {
            if (s[r] != '*') s[l++] = s[r];
            else l -= 1;
            r += 1;
        }
        s.resize(l);
        return s;
    }
    string removeStars(string s) {
        return removeStars_2(s);
    }
};