/*
https://leetcode.com/problems/longest-substring-without-repeating-characters

Solutlins1. sliding window with hash map (set)
time: o(n)
space: o(n)

Solutlins2. sliding window with hash map(char, int). find next left window from map. Sol1 improvement
time: o(n) 
space: o(n)

Solutions3. sliding window with array (128 char)
time: o(n)
space: o(n) improved from sol2 (map -> array)

*/
class Solution {
public:
    int lengthOfLongestSubstring_1(string& s) {
        int n = s.size();
        int l = 0, r = 0;
        int res = 0;
        unordered_set<char> m;
        while (l<=r && r<n) {
            if (m.count(s[r])) {
                m.erase(m.find(s[l++]));
            }
            else {
                m.insert(s[r++]);
                res = std::max(res, (int)m.size());
            }
        }
        return res;
    }
    int lengthOfLongestSubstring_2(string& s) {
        unordered_map<char, int> m;
        int l = 0;
        int r = 0;
        int res = 0;
        while (r<s.size()) {
            if (m.count(s[r]) && m[s[r]] >= l) {
                l = m[s[r]] + 1;
            }
            res = max(res, r - l + 1);
            m[s[r]] = r;
            r++;
        }
        return res;
    }
    int lengthOfLongestSubstring_3(string& s) {        
        vector<int> arr(128, -1);
        int l=0, r=0;
        int res = 0;
        while (r<s.size()) {
            if (arr[s[r]] >= l)
                l = arr[s[r]] + 1;
            arr[s[r]] = r;
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
    int lengthOfLongestSubstring(string s) {
        return lengthOfLongestSubstring_2(s);
    }
};