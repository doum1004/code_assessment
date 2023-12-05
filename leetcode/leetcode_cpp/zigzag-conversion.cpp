/*
https://leetcode.com/problems/zigzag-conversion

Solution. Traverse and store on level
time: o(n)
space: o(n)
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        bool dir = true;
        int level = 0;
        vector<string> slot(min(numRows, int(s.size())));
        for (auto c : s) {
            slot[level] += c;
            level += dir ? 1 : -1;
            if (level == numRows-1 || level == 0) dir = !dir;
        }

        string res;
        for (auto values : slot)
            res += values;
        return res;
    }
};