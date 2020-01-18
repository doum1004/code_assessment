#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// expand from center
// expand from index to check palindromic
// time: log (n^2) log(n)
// space: n(1)

// TODO
// Longest Palindromic Substring Manacher's Algorithm
// https://www.youtube.com/watch?v=V-sEwsca1ak

class Solution {
public:
    string longestPalindrome(string s) {
        int start=0, len = -1;
        int n = s.size();
        for (int i=0; i<n; ++i) {
            auto l = i, r = i;
            while (s[l] == s[r+1]) { // !! skip same char
                r++;
                i++;
            }
            while (l - 1 >= 0 && r + 1 < n && s[l-1] == s[r+1]) {
                l--;
                r++;
            }
            
            if (r-l+1 > len) {
                len = r-l+1;
                start = l;
            }
        }
        
        return s.substr(start, len);
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