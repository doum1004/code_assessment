#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/longest-palindromic-substring/

// solution1. expand from center
time: o(n^2) : iterate(n) expand(n)
space: o(1)

babad
*         b
 *        a
  *       aba
  l
  r
 l r
   *.     a
    *.    d
    
babbad
  *       abba
  lr
 l  r

// solution2. manacher's al

*/

class Solution {
public:
    string longestPalindrome_1(string& s) {
        if (s.size() < 2) return s;
        int maxLength = 1;
        int start = 0;
        for (int i=0; i<s.size(); ++i) {
            int l = i;
            while (i < s.size()-1 && s[i+1] == s[l]) i++;

            int r = i;
            while (l >= 0 && r<s.size() && s[l] == s[r]) {
                int length = r - l + 1;
                if (maxLength < length) {
                    start = l;
                    maxLength = length;
                }
                l--;
                r++;
            }
            if (r == s.size() - 1) break;
        }
        return s.substr(start, maxLength);
    }
};

int main()
{
    assert(Solution().longestPalindrome(
        "babad"
    ) == ("bab"));
    assert(Solution().longestPalindrome(
        "cbbd"
    ) == ("bb"));
    return 0;
}