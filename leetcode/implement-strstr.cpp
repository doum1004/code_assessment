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
KMP helps not to go back to begin of iteration in haystack and needle indicating where to begin in needle since we have been threw
https://www.youtube.com/watch?v=GTJr8OvyEVQ
https://www.youtube.com/watch?v=V5-7GzOfADQ
https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP
// time: o(n+m). m(build kmp process) + n(iterate haytext) + m(iterate needle)
// space: o(m). kmp(lsp)

1. build lsp(longest suffix-preffix) table by KMP process for needle string.
1.1. build list of next index. v(n,0)
1.2. iterate string with l,r
1.2.1 if s[l] == s[r]: v[r] = l+1; r++; l++;
1.2.2 else if (l) l = v[l-1]
1.2.3 else v[r] = 0; r++
2. iterate text with kmp process of pattern
3.  if pattern isn't same, take next pattern idx from kmp process

ex) abcaby

1) init
abcaby
000000

2)
00
abcaby
lr

3)
000
abcaby
l r

3)
0001
abcaby
l  r

4)
00012
abcaby
 l  r

5)
000120
abcaby
  l  r
l    r
  
ex) aabaabaaa
aabaabaaa
010123454

*/

class Solution {
public:
    int strStr_bruteforce(string &haystack, string &needle) {
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;
        
        int n1 = haystack.size();
        int n2 = needle.size();
        
        for (int i=0; i<n1; ++i) {
            if (n1-i < n2) return -1;
            
            auto p1 = i;
            auto p2 = 0;
            while (p1<n1 && p2<n2 && haystack[p1] == needle[p2]) {
                p1++; p2++;
            }
            if (p2 == n2) return i;
        }
        
        return -1;
    }
    
    int strStr_kmp(string &haystack, string &needle) {
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;
        
        int n1 = haystack.size();
        int n2 = needle.size();
        
        // build lsp table by kmp
        vector<int> lsp(n2, 0);
        int l=0, r=1;
        while (r<n2) {
            if (needle[l] == needle[r]) {
                lsp[r] = l+1;
                l++; r++;
            }   
            else if (l) {
                l = lsp[l-1];
            }
            else {
                lsp[r] = 0;                
                r++;
            }
        }
        
        for (int i=0, j=0; i<n1;) {
            if (n2-j > n1-i) return -1; // exit early
                
            if (haystack[i] == needle[j]) {
                i++; j++;
            }
            else {
                j ? j = lsp[j-1] : ++i;
            }
            
            if (j == n2) return i - j;
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