/*
https://leetcode.com/problems/determine-if-two-strings-are-close

1. list and sort
time: o(nlogn) n(word size) + nlogn (26log26)
space: o(n)
Swap or Replace all occurence conditions
1. same set values (to enable swap, the char exist on each other)
ex) a,b == a,b
2. same frequency (no matter chars, to replace)
ex) a:4, b:1 == b:4, a:1
*/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> c1(26, 0);
        vector<int> c2(26, 0);
        for (int i=0; i<word1.size(); ++i) {
            c1[word1[i] - 'a']++;
            c2[word2[i] - 'a']++;
        }
        for (int i=0; i<26; ++i) {
            if ((c1[i] && !c2[i]) || (!c1[i] && c2[i])) return false;
        }
        sort(begin(c1), end(c1));
        sort(begin(c2), end(c2));
        return c1 == c2;
    }
};