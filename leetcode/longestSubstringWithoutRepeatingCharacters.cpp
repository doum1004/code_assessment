#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding door (it can be o(n) sliding door)
        // time complexcity: o(n) * 2 = o(n)
        // space complexcity: o(k<n)
        auto n = s.size();
        if (n < 2) return n;

        auto cache = unordered_set<char>();
        int i = 0, j = 0;
        int ans = 0;
        while (i < n && j < n) {
            if (cache.find(s[j]) == cache.end()) {
                cache.insert(s[j++]);
                ans = max(ans, j-i);
            }
            else {
                cache.erase(s[i++]);
            }
        }

        return ans;
    }
};

int main()
{
    assert(Solution().lengthOfLongestSubstring("abcabcbb") == 3);
    assert(Solution().lengthOfLongestSubstring("aab") == 2);
    assert(Solution().lengthOfLongestSubstring("pwwkew") == 3);
    assert(Solution().lengthOfLongestSubstring("ohvhjdml") == 6);
    assert(Solution().lengthOfLongestSubstring("abba") == 2);
    return 0;
}