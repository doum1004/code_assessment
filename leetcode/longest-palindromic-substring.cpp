#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

/**

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
    string longestPalindrome(string s) {
        int len_palindorme = 0;
        int start=-1;
        for (int i=0; i<s.size(); ++i) {
            int l = i;
            while (i+1 < s.size() && s[i+1] == s[i]) i++;
            int r = i;
            while (l >= 0 && r<s.size() && s[l] == s[r]) {
                if (len_palindorme < r-l+1) {
                    len_palindorme = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
            if (r+1 == s.size()) break;
        }
        return (start >= 0) ? s.substr(start,len_palindorme) : "";
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