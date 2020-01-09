#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;

        int start = 0, maxlen = -1;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            auto l = i, r = i;
            while (s[l] == s[r+1]) { // skip same char
                r++;
                i++;
            }

            while (l - 1 >= 0 && r + 1 < n && s[l-1] == s[r+1]) {
                r++;
                l--;
            }
            
            if (r-l+1 > maxlen) {
                maxlen = r-l+1;
                start = l;
            }
        }
        
        return s.substr(start, maxlen);
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