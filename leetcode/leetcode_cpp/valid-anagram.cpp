/*
https://leetcode.com/problems/valid-anagram

Solution1. sort
time: o(nlogn)
space: o(1)

Solution2. map
time: o(1)
space: o(n)

Solution3. array
time: o(1)
space: o(1)

*/
class Solution {
public:
    bool isAnagram_1(string& s, string& t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i=0; i<s.size(); ++i)
            if (s[i] != t[i]) return false;
        return true;
    }

    bool isAnagram_2(string& s, string& t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> m;
        for (int i=0; i<s.size(); ++i) {
            m[s[i]]++;
        }
        for (int i=0; i<t.size(); ++i) {            
            m[t[i]]--;
            if (m[t[i]] == 0)
                m.erase(m.find(t[i]));
        }
        return m.size() == 0;        
    }

    bool isAnagram_3(string& s, string& t) {
        if (s.size() != t.size()) return false;
        int arr[26] = {0};
        for (int i=0; i<s.size(); ++i) {
            arr[s[i] - 'a']++;  
            arr[t[i] - 'a']--;
        }
        for (int i=0; i<26; ++i) {
            if (arr[i] != 0)
                return false;
        }
        return true;
    }
    bool isAnagram(string s, string t) {
        return isAnagram_3(s, t);
    }
};