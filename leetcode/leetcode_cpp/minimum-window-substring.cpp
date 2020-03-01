#include <iostream>
#include <cassert>

#include <math.h>
#include <vector>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/minimum-window-substring/

// Solution1. Sliding window
// time: o(t+s) 2*s + t
// space: o(t+s)

ex) ADOBEA AB

1. iterate target and put them in map
AB
A = 1
B = 1

2. iterate input with r, if matched value in map is larger than 0, count++. and m[c]--
3. if count == same as target size
4.   find l position which can left most in range (while doing m[l]++)
5.   then store min size, start, end index
6.   move l++, counter--

ADOBEA
   *
1  2
A=0
B=0
D=-1
O=-1


1. iterate from start
2. 

*/


class Solution {
public:
    string minWindow_slidingwindow(string s, string t) {
        int n_s = s.size();
        int n_t = t.size();
        if (n_s == 0 || n_t == 0) return "";
        
        unordered_map<char, int> m;
        for (auto &c:t) m[c]++;
        
        int l=0, r=0, counter=0, min_starter=0, min_len=INT_MAX;
        while (r<n_s) {
            auto c = s[r];
            if (m[c]-- > 0) counter++;
            while (counter == n_t) {
                while (l<r && ++m[s[l]] < 1) l++;
                if (min_len > r-l+1) {
                    min_len = r-l+1;
                    min_starter = l;
                }
                l++;
                counter--;
            }
            r++;
        }
        
        return (min_len == INT_MAX) ? "" : s.substr(min_starter, min_len);
    }
    
    string minWindow(string s, string t) {
        return minWindow_slidingwindow(s, t);
    }
};

int main()
{
    assert(Solution().minWindow("ADOBECODEBANC", "ABC")
        == "BANC");

    return 0;
}