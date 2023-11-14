#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
https://leetcode.com/problems/valid-palindrome/

Sol1. two pointers
time: o(n)
space: o(1)

*/
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }

            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }
        return true;
    }
};