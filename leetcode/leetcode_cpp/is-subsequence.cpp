#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
https://leetcode.com/problems/is-subsequence

sol0. Recursive
time: o(n^2)
space: o(n)

Solution1. Two Pointer
time: o(n)
space: o(1)

Solution2. Follow up problem. Using Map 
time: o(n) m + n
space: o(m)
*/
class Solution {
public:
    bool isSubsequence_1(string& s, string& t) {
        int l = 0, r = 0;
        while (l < s.size() && r < t.size()) {
            if (s[l] == t[r]) l++;
            r++;
        }
        return l == s.size();
    }
    bool isSubsequence_2(string& s, string& t) {
        unordered_map<char, vector<int>> m;
        for (int i=0; i<t.size(); ++i) {
            m[t[i]].push_back(i);
        }

        int l=-1;
        for (int i=0; i<s.size(); ++i) {
            if (!m.count(s[i])) return false;
            auto& idxList = m[s[i]];
            auto x = upper_bound(idxList.begin(), idxList.end(), l);
            if (x == idxList.end()) return false;
            l = *x;
        }
        return true;
    }
    bool isSubsequence(string s, string t) {
        return isSubsequence_2(s, t);
    }
};