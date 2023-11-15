/*
https://leetcode.com/problems/ransom-note

solution1. map[char] count
time: o(n)
space: o(n)

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> m;
        for (auto c : magazine) {
            m[c]++;
        }

        for (auto c : ransomNote) {
            if (m[c] == 0)
                return false;
            m[c]--;
        }

        return true;
    }
};