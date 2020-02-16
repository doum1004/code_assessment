#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/implement-strstr/

// solution1. std find

// solution2. brute force
// time: o(n*m) n: haystack m: needle compare needle n-m times
// space: o(1)
1. iterate i in source string
2. (*this condition make it faster) if left over source size is bigger than target size, return -1
3. iterate both strings from i (we could improve if we remmber next potension search i)

// solution3. KMP
https://www.youtube.com/watch?v=GTJr8OvyEVQ
https://www.youtube.com/watch?v=V5-7GzOfADQ
https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP
// time: o(n+m). m(build kmp process) + n(itearte text)
// space: o(m)90

kmp process work like below
1) abcaby
   000120

2) aabaabaaa
   010123452

1. build kmp process (list of next index base on prefix, surfix)
2.  iterate pattern (l=0, r=1) vector[0] = 0
3.      if s[l] == s[r] vector[r] = l+1; l++ r++
4.      else if (l) l = vector[l-1]
5.      else vector[r] = 0 r++
6. iterate text with kmp process of pattern
7.  if pattern isn't same, take next pattern idx from kmp process

*/

class Solution {
public:
    int strStr_bruteforce(string &haystack, string &needle) {
        if (needle.empty()) return 0;
        if (needle.size() > haystack.size()) return -1;
        
        int n1 = haystack.size();
        int n2 = needle.size();
        for (int i=0; i<n1; ++i) {
            if (n1-i < n2) return -1;
            
            int p1 = i;
            int p2 = 0;
            while (p1 < n1 && p2 < n2 && haystack[p1] == needle[p2]) {
                p1++;
                p2++;
            }
            if (p2 == n2) return i;
        }
        
        return -1;
    }
    
    vector<int> kmpProcess(string &pattern) {
        if (pattern.empty()) return vector<int>();
        int n = pattern.size();
        vector<int> v(n, 0);
        v[0] = 0;
        for (int l=0, r=1; r<n;) {
            if (pattern[l] == pattern[r]) {
                v[r] = l + 1;
                r++, l++;
            }
            else if (l) {
                l = v[l-1];
            }
            else {
                v[r] = 0;
                r++;
            }
        }
        
        return v;
    }
    
    int strStr_kmp(string &haystack, string &needle) {
        if (needle.empty()) return 0;
        int n1 = haystack.size();
        int n2 = needle.size();
        if (n1 < n2) return -1;
        
        auto lps = kmpProcess(needle);
        for (int i=0, j=0; i<n1;) {
            if (haystack[i] == needle[j]) {
                i++, j++;
            }
            else {
                j ? j = lps[j-1] : i++;
            }
            
            if (j == n2) return i-j;
        }
        
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        //return haystack.find(needle);
        //return strStr_bruteforce(haystack, needle);
        return strStr_kmp(haystack, needle);
    }
};

int main()
{
    assert(Solution().strStr("hello", "ll") == (2));
    assert(Solution().strStr("aaaaa", "bba") == (-1));
    return 0;
}