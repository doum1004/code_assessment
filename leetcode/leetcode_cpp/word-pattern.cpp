/*
https://leetcode.com/problems/word-pattern

Solution1. hashmap
time: o(n)
space: o(n)

1. get list of string
2. store hashmap of char: string, string[char]. And compare them in iteration

*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> l;
        string temp;
        for (int i=0; i<=s.size(); ++i) {
            if (i == s.size() || isspace(s[i])) {
                l.push_back(temp);
                temp = "";
            } else {
                temp += s[i];
            }
        }
        if (pattern.size() != l.size()) return false;

        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        for (int i=0; i<pattern.size(); ++i) {
            auto value_char = pattern[i];
            auto value_string = l[i];
            if (m1.count(value_char) && m1[value_char] != value_string)
                return false;
            if (m2.count(value_string) && m2[value_string] != value_char)
                return false;
            m1[value_char] = value_string;
            m2[value_string] = value_char;
        }
        return true;
    }
};