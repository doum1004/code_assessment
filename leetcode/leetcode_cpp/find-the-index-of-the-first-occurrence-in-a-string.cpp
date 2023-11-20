/*
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

Solution1. stl find
time: o(n)
space: o(1)

Solution2. substr
time: o(n) m*n
space: o(1)

Solution3. KPM longest prefix and suffix
time: o(n) m+n
space: o(1)
https://youtu.be/0iDiUuHZE_g

*/
class Solution {
public:
    int strStr_1(string& haystack, string& needle) {
        return haystack.find(needle);
    }

    int strStr_2(string& haystack, string& needle) {
        for (int i=0; i<haystack.size() && haystack.size() - i >= needle.size(); ++i) {
            if (haystack[i] == needle[0]) {
                if (haystack.substr(i, needle.size()) == needle) return i;
            }
        }
        return -1;
    }

    int strStr_3(string& haystack, string& needle) {
        vector<int> lps(needle.size(), 0);
        int pre = 0;
        for (int i=1; i<needle.size(); ++i) {
            while (pre > 0 && needle[pre] != needle[i])
                pre = lps[pre - 1];
            if (needle[pre] == needle[i]) {
                pre += 1;
                lps[i] = pre;
            }
        }

        int n = 0;
        for (int i=0; i<haystack.size(); ++i) {
            while (n > 0 && haystack[i] != needle[n])
                n = lps[n-1];
            if (haystack[i] == needle[n])
                n += 1;
            if (n == needle.size())
                return i - n + 1;
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        return strStr_3(haystack, needle);
    }
};