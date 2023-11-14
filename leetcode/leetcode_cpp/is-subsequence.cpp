#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
https://leetcode.com/problems/is-subsequence/
solution1. two pointers
time: n(o)
space: n(1)

sol2. Recursive
time: o(n^2)
space: o(n)

*/

class Solution {
public:
    int isSubsequence_recursive(string& s, string& t, int i, int j) {
        if (i == 0 || j == 0) return 0;
        if (s[i-1] == t[j-1]) return 1 + isSubsequence_recursive(s, t, i - 1, j - 1);
        return isSubsequence_recursive(s, t, i, j - 1);
    }

    bool isSubsequence_recursive(string& s, string& t) {
        if (s == t) return true;
        int m = s.size();
        int n = t.size();
        if (m > n) return false;
        return isSubsequence_recursive(s, t, m, n) == m;
    }

    bool isSubsequence_1(string& s, string& t) {
        if (s == t)
            return true;

        int i = 0, j = 0;
        int m = s.size();
        int n = t.size();
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;            
        }
        return i == m;
    }

    bool isSubsequence(string s, string t) {
        return isSubsequence_recursive(s,t);
    }
};