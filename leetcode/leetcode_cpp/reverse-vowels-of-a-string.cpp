/*
Solution1. One pointer
time: o(n) n + n
space: o(n) vowels

Solution2. One pointer
time: o(n)
space: o(1)
*/
class Solution {
public:
    string reverseVowels_1(string& s) {
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> v;
        for (int i=s.size()-1; i>=0; i--) {
            if (vowels.count(s[i])) v.push_back(s[i]);
        }

        int l = 0;
        for (int i=0; i<s.size(); i++) {
            if (vowels.count(s[i])) s[i] = v[l++];
        }
        return s;
    }
    string reverseVowels_2(string& s) {
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0, r = s.size()-1;
        while (l<r) {
            while (!vowels.count(s[l]) && l < r) l++;
            while (!vowels.count(s[r]) && l < r) r--;
            if (l < r) {
                swap(s[l], s[r]);
                l += 1;
                r -= 1;
            }
        }

        return s;
    }
    string reverseVowels(string s) {
        return reverseVowels_2(s);
    }
};