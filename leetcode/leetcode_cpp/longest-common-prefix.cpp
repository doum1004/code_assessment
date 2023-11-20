/*
https://leetcode.com/problems/longest-common-prefix

Solution1. Iterate. find window
time: o(n)
space: o(1)

*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        auto& res = strs[0];
        int r = res.size();
        for (int i=1; i<strs.size(); ++i) {
            auto&s = strs[i];
            r = std::min(r, (int)s.size());
            for (int j=0; j<s.size() && j<r; j++) {
                if (res[j] != s[j]) {
                    if (j == 0) return "";
                    r = j;
                    break;
                }
            }
        }
        return res.substr(0, r);
    }
};