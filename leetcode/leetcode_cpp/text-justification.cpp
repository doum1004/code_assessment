/*
https://leetcode.com/problems/text-justification

Solution1. Iterate word and give right space using modulo
time: o(n)
space: o(n)

ex) "example" "of" "text" maxWidth = 18 (total 13)
for i; i<5(leftspace); ++i
  idx = i % cursize-1
- 'example ' 'of' 'text' (i = 0, idx = 0) 14
- 'example ' 'of ' 'text' (i = 1, idx = 1) 15
- 'example  ' 'of ' 'text' (i = 2, idx = 0) 16
- 'example  ' 'of  ' 'text' (i = 2, idx = 0) 17
- 'example   ' 'of  ' 'text' (i = 2, idx = 0) 18
-> 'example   of  text'

*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> cur;
        int nbWords = 0;
        for (auto word : words) {
            // wordSize + space + nbWords > maxWidth
            if (word.size() + cur.size() + nbWords > maxWidth) {
                // add space
                for (int i=0; i<maxWidth - nbWords; ++i) {
                    int idx = cur.size() == 1 ? 0 : i % (cur.size() - 1);
                    cur[idx] += ' ';
                }
                res.push_back("");
                for (auto curWord : cur) res.back() += curWord;
                cur.clear();
                nbWords = 0;
            }
            cur.push_back(word);
            nbWords += word.size();
        }

        // last words (left allignment)
        string lastWord;
        for (auto word : cur) lastWord += word + ' ';
        lastWord = lastWord.substr(0, lastWord.size() - 1);
        while (lastWord.size() < maxWidth) lastWord += ' ';
        res.push_back(lastWord);
        return res;
    }
};