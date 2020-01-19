#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/partition-labels/

// Greedy by selection
// time: o(n)
// space: o(n)

//[a] = 5
//[b] = 7
//[c] = 4
//[d] = 6
//[e] = 11

//j=0, anchor=0
//012345678901
//abccaddbeffe
//i             j=5
// i            j=7
//  i           j=7
// ...
//       i      j=7 ans.push_back(i-anchor+1) anchor=i+1



class Solution {
public:
    vector<int> partitionLabels(string S) {
        auto map = unordered_map<char, int>();
        for (int i=0; i<S.size(); ++i) {
            map[S[i]] = i;
        }
        
        vector<int> ans;
        int j = 0, anchor = 0;
        for (int i=0; i<S.size(); ++i) {
            j = max(j, map[S[i]]);
            if (i == j) {
                ans.push_back(i-anchor+1);
                anchor = i+1;
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