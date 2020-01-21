#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

// https://leetcode.com/problems/group-anagrams/

// solution 1. sort string. and store it map in vector
// time: o(n*klogk) n=strs.size() k = str.size()
// space: o(n*k)

// solution 2. if only alpha str, counting sort for reduce time complexcity

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto map = unordered_map<string, vector<string>>();
        for (auto &s : strs) {
            string sorts = s;
            sort(sorts.begin(), sorts.end());
            map[sorts].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto arr : map) {
            ans.push_back(arr.second);
        }
        return ans;
    }
};

int main()
{
    auto input1 = vector<string> {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto expect1 = vector<vector<string>>();
    expect1.push_back(vector<string> {"ate","eat","tea"});
    expect1.push_back(vector<string> {"nat","tan"});
    expect1.push_back(vector<string> {"bat"});
    assert(Solution().groupAnagrams(input1)
        == (expect1));

    return 0;
}