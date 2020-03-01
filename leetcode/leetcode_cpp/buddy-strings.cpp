#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/buddy-strings/

// naive solution
// time: o(n)
// space: o(1) : since it only takes up to 26

1. check size
2. iterate string A, B.
2.1 check diff count. > 2 return false
2.2 save diff char to check swap able
2.3 in case of no diff, make sure there is no diff and more than one same char

*/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        
        int diffcount = 0;
        char diff1 = '\0';
        char diff2 = '\0';
        //unordered_set<int> s;
        vector<int> s(26, 0);
        
        bool result = false;
        for (int i=0; i<A.size(); ++i) {
            if (A[i] != B[i]) {
                if (++diffcount > 2) return false;
                
                if (diff1 == '\0') {
                    diff1 = A[i];
                    diff2 = B[i];
                }
                else {
                    result = diff1 == B[i] && diff2 == A[i];
                    if (!result) return false;
                }
            }
            if (s[A[i]-'a'] == 0) s[A[i]-'a']++;
            //if (s.find(A[i]-'a') == s.end()) s.insert(A[i] - 'a');
            else if (!result) result = true;
        }
        
        return result && diffcount != 1;
    }
};

int main()
{
    assert(Solution().buddyStrings("ab", "ba") == (true));
    assert(Solution().buddyStrings("ab", "ab") == (false));
    assert(Solution().buddyStrings("aa", "aa") == (true));
    assert(Solution().buddyStrings("aaaaaaabc", "aaaaaaacb") == (true));
    assert(Solution().buddyStrings("", "aa") == (false));
    return 0;
}