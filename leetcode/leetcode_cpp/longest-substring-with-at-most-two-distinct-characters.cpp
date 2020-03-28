#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

- solution1. slinding window (l,r)
- time: o(n) 2n
- space: o(n)

1. iterate by r to count on map
2. if it hits more than target, iterate by l to decrease count on map till erase
3. otherwise save res

- solution2. move 
- time: o(n)
- space: o(1)

*/


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct_slindingwindow(string& s) {
        int n = s.size();
        int l = 0, r = 0, res = 0, d = 2;
        unordered_map<char, int> h;
        while (r<n) {
            h[s[r]]++;
            if (h.size() > d) {
                while (h.size() > d) {
                    h[s[l]]--;
                    if (h[s[l]] == 0) h.erase(s[l]);
                    l++;
                }
            }
            else {
                res = max(res, r-l+1);
            }
            r++;
        }
        
        return res == 0 ? n : res;
    }
    /**
    abbbbaddddddddd
         l
                  r
         c
    */
    int lengthOfLongestSubstringTwoDistinct_nospace(string& s) {
        int l=0,c=0,res=0;
        for (auto r=0; r<s.size(); ++r) {
            if (s[r] != s[c]) {
                if (c != 0 && s[r] != s[c-1]) l = c;
                c = r;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
    
    int lengthOfLongestSubstringTwoDistinct(string s) {
        //return lengthOfLongestSubstringTwoDistinct_slindingwindow(s);
        return lengthOfLongestSubstringTwoDistinct_nospace(s);
    }
};

int main()
{
    assert(Solution().lengthOfLongestSubstringTwoDistinct("eceba") == (3));
    assert(Solution().lengthOfLongestSubstringTwoDistinct("ccaabbb") == (5));
    return 0;
}