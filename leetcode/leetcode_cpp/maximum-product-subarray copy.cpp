#include <iostream>
#include <cassert>

#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/valid-anagram/

// Solution 1. sort
// time: o(nlogn)
// space: o(1)

// Solution 2. hash table or array(faster)
// time: o(n)
// space: o(n)

*/

class Solution {
public:
    bool isAnagram_sort(string &s, string &t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
    }
    
    bool isAnagram_set(string &s, string &t) {
        unordered_map<char, int> h;
        for (auto &c:s) h[c]++;
        for (auto &c:t) if (--h[c] == 0) h.erase(c);
        return h.size() == 0;
    }
    
    bool isAnagram_array(string &s, string &t) {
        int h[26] = {0};
        for (auto &c:s) h[c-'a']++;
        for (auto &c:t) --h[c-'a'];
        for (auto i=0; i<26; ++i) if (h[i] != 0) return false;
        return true;
    }
    
    bool isAnagram(string s, string t) {
        //return isAnagram_sort(s, t);
        //return isAnagram_set(s, t);
        return isAnagram_array(s, t);
    }
};

int main()
{
    assert(Solution().isAnagram("anagram", "nagaram") == (true));
    assert(Solution().isAnagram("rat", "car") == (false));

    return 0;
}
