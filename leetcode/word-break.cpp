#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/word-break/

// "leetcode" -> ["leet", "code"]
// l ->
// le ->
// leet ->
// c ->
// co ->
// code ...

// BFS
// time: o(n^2)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() < 1 || wordDict.size() < 1) return false;
        
        auto wordMap = unordered_set<string>();
        for (auto &s : wordDict) {
            wordMap.insert(s);
        }
        
        queue<int> q;
        q.push(0);
        
        auto visited = unordered_set<int>();
        while (!q.empty()) {
            auto l = q.front();
            q.pop();
            
            if (visited.find(l) == visited.end()) {
                for (int r = l + 1; r<=s.size(); ++r) {
                    if (wordMap.find(s.substr(l, r - l)) != wordMap.end()) {
                        if (r == s.size()) {
                            return true;
                        }
                        q.push(r);
                    }
                }
                visited.insert(l);
            }
        }
        
        return false;
    }
};

int main()
{
    auto input1_1 = vector<string> {"leet", "code"};
    assert(Solution().wordBreak(
        "leetcode", input1_1
    ) == (true));
    return 0;
}