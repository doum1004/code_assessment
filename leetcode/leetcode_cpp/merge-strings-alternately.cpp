/*
https://leetcode.com/problems/merge-strings-alternately

Soltuion1. Two Pointer
time: o(n)
space: o(1)

Solution2. Single Pointer
time: o(n)
space: o(1)
*/
class Solution {
public:
    string mergeAlternately_1(string& word1, string& word2) {
        int l = 0, r = 0;
        string res;
        while (l < word1.size() || r < word2.size()) {
            if (l < word1.size())
                res += word1[l++];
            if (r < word2.size())
                res += word2[r++];
        }
        return res;
    }
    string mergeAlternately_2(string& word1, string& word2) {
        string res;
        for (int i=0; i<max(word1.size(), word2.size()); ++i) {
            if (i < word1.size())
                res += word1[i];
            if (i < word2.size())
                res += word2[i];
        }
        return res;
    }
    string mergeAlternately(string word1, string word2) {
        return mergeAlternately_2(word1, word2);
    }
};