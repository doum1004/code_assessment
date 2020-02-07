#include <iostream>
#include <cassert>

#include <math.h>
#include <vector>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/minimum-window-substring/

// Solution1. sliding window moves r till all found. and move l to adjust min condition in r range. And shift l->l+1 and do it again till the end.
// time: o(|s| + |t|) : init map t.size + iterate s.size() * 2
// space: o(|s| + |t|) : init map t.size() + map rest of num s.size()

*/

class Solution {
public:
    string minWindow_linear(string &s, string &t) {
        if (s.size() == 0 || t.size() == 0) return "";
        // store target chars in hash to retirve faster
        unordered_map<char, int> ts;
        for (auto &c:t) {
            ts[c]++;
        }
        
        unordered_map<char, vector<int>> v;
        
        string ans;
        int min_ans = INT_MAX;
        int cur=0;
        while (cur<s.size()) {
            auto c = s[cur];
            if (ts.find(c) != ts.end()) {
                if (v[c].size() == ts[c]) {
                    v[c].erase(v[c].begin());
                }
                    
                v[c].push_back(cur);
                cout << c << " : " << v[c].size() << endl;
                if (v.size() == ts.size()) {
                    auto l = INT_MAX;
                    auto r = INT_MIN;
                    
                    auto valid = true;
                    for (auto it = v.begin(); it != v.end(); it++) {
                        if (it->second.size() < ts[it->first]) {
                            valid = false;
                            break;
                        }
                        
                        for (auto &ii:it->second) {
                            l = min(l, ii);
                            r = max(r, ii);
                        }
                    }
                    if (valid && min_ans > r-l+1) {
                        min_ans = r-l+1;
                        ans = s.substr(l, min_ans);
                    }
                }
            }
            cur++;
        }
        
        return ans;
    }
    
    
    string minWindow_slidingwindow(string &s, string &t) {
        if (s.size() == 0 || t.size() == 0) return "";
        
        unordered_map<char, int> m;
        for (auto &c:t) m[c]++;
        
        // 0 1 0 0
        // D A B C (ABC)
        // l     r
        //   l   r
        //     l r
        int counter = 0;
        int l=0, r=0, min_length = INT_MAX, min_start = 0;
        while (r < s.size()) {
            auto r_c = s[r];
            if (m[r_c] > 0) counter++;
            m[r_c]--;
            while (counter == t.size()) {
                while (l < r && ++m[s[l]] < 1) l++;
                
                if (min_length > r - l + 1) {
                    min_length = r - l + 1;
                    min_start = l;
                }
                l++;
                counter--;
            }
            r++;
        }
        return min_length == INT_MAX ? "" : s.substr(min_start, min_length); //check for edge case & return the result
    }
    
    string minWindow(string s, string t) {
        //return minWindow_linear(s, t);
        return minWindow_slidingwindow(s, t);
    }
};

int main()
{
    assert(Solution().minWindow("ADOBECODEBANC", "ABC")
        == "BANC");

    return 0;
}