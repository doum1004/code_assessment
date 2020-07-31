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
    bool dfs(unordered_set<string>& wordBooks, string s) {
        if (s.empty()) return true;
        
        for (auto word:wordBooks) { // D
            auto scopy = s;
            bool found = false;
            while (scopy.find(word) == 0) { // W + W * N
                found = true;
                scopy.erase(0, word.size());
            }
            if (found && dfs(wordBooks, scopy)) return true;
        }
        
        return false;
    }
    
    bool dfs(string s, vector<string>& wordDict) {
        unordered_set<string> wordBooks(wordDict.begin(), wordDict.end());
        return dfs(wordBooks, s);
    }
    
    bool bfs(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        queue<int> q;
        q.push(0);
        
        unordered_set<int> v;
        while (!q.empty()) {
            auto l = q.front();
            q.pop();
            
            if (v.find(l) != v.end()) continue;
            v.insert(l);
            
            for (int r=l; r<s.size(); ++r) {
                auto str = s.substr(l, r-l+1);
                if (wordSet.find(str) != wordSet.end()) {
                    if (r == s.size() - 1) return true;
                    q.push(r+1);
                }
            }
        }
        
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        if (wordDict.size() < 1) return false;
        
        //return dfs(s, wordDict);
        return bfs(s, wordDict);
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
