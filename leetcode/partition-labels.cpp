#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/partition-labels/

// Solution1. Greedy (why greedy?)
// time: o(n). n+n
// space: o(1). map to store 26 chars only
1. map<char, int>. it contains last index of char
2. iterate s,   and store last most index of char while iterating.
3.              if i is equal to last most index. then store. and update left(anchor)

ex)
l = 0, max_idx = 0

    012345678901
    abccaddbeffe
i=0 max_idx = 4
i=1 max_idx = 7
...
i=7 store (i-l+1, 8) l =8
i=8 max_idx = 11
...
i=11 store (i-l+1, 4)

*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        unordered_map<char, int> m;
        for (int i=0; i<S.size(); ++i) {
            m[S[i]] = i;
        }
        
        vector<int> ans;
        int l=0, max_idx=0;
        for (int r=0; r<S.size(); ++r) {
            max_idx = max(max_idx, m[S[r]]);
            if (r == max_idx) {
                ans.push_back(r-l+1);
                l = r+1;
            }
        }
        
        return ans;
    }
};

int main()
{
    assert(Solution().partitionLabels("ababcbacadefegdehijhklij") == (vector<int>{9,7,8}));
   
    return 0;
}