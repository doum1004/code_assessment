/*
https://leetcode.com/problems/determine-if-two-strings-are-close

1. list and sort
time: o(nlogn) n(word size) + nlogn (26log26)
Swap or Replace all occurence
has to meet
1. same frequency (no matter chars)
ex) a:4, b:1 == b:4, a:1
2. same set values (that can replace or swap)
ex) a,b == a,b
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