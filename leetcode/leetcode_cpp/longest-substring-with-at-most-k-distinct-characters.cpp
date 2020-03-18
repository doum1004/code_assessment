#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

//Solution1. sliding window
//time: o(n)
//space: o(1). unique charaters(26)

*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct_slidingwindow(string& s, int k) {
        unordered_map<char, int> dict;
        int l = 0, r = 0, res = 0;
        while (r < s.size()) {
            dict[s[r++]]++;
            while (l <= r && dict.size() > k) {
                dict[s[l]]--;
                if (dict[s[l]] == 0)
                    dict.erase(s[l]);
                l++;
            }
            
            if (dict.size() <= k) {
                res = max(res, r-l);
            }
        }
        return res;
    }
    
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        return lengthOfLongestSubstringKDistinct_slidingwindow(s, k);
    }
};

int main()
{
    assert(Solution().lengthOfLongestSubstringKDistinct("eceba", 2)
        == 3);
    assert(Solution().lengthOfLongestSubstringKDistinct("aa", 1)
        == 2);
    assert(Solution().lengthOfLongestSubstringKDistinct("aeccccccceba", 3)
        == 10);
    return 0;
}