/*
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

1. Sliding Window
time: o(n)
space: o(1)
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> c {'a', 'e', 'i', 'o', 'u'};
        int n = s.size(), r = 0;
        int cnt = 0, res = 0;
        while (r < n) {
            if (c.count(s[r])) cnt += 1;
            if (r >= k && c.count(s[r-k])) cnt -= 1;
            r += 1;

            res = max(res, cnt);
        }
        return res;
    }
};