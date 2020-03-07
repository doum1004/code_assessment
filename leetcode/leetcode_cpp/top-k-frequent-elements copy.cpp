#include <iostream>
#include <cassert>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

//Solution1. sliding window (TwoPointers with map or array). map is slower (erase()->o(n), allocation overhead, potential reallocation)
//time:o(n)
//space:o(k). k+1
1. iteation by two pointers (l=0,r=-1)
2. while (r<n)
2.1 if size <= k
2.1.1 if r > -1: res = max(res, r-l+1)
2.1.2 r++. store s[r] count in map
2.2 else
2.2.1 decrease count in map. and erase if 0
2.2.2 l++

*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct_twoPointers_map(string &s, int k) {
        int n = s.size(), l=0, r=0, res = 0;
        unordered_map<int,int> counter;
        
        for (;r<n;++r) {
            counter[s[r]]++;
            while (counter.size() > k) {
                if (--counter[s[l]] == 0)
                    counter.erase(s[l]);
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
    
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        return lengthOfLongestSubstringKDistinct_twoPointers_map(s, k);
    }
};

int main()
{
    assert(Solution().lengthOfLongestSubstringKDistinct("eceba", 2) == 3);
    assert(Solution().lengthOfLongestSubstringKDistinct("aa", 1) == 2);
    return 0;
}