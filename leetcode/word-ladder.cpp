#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/word-ladder/

// BFS
// time: o(n*m) n = number of words, m = size of word
// space: o(n*m) 

hit / cog
hot dot dog lot log cog

BFS to find shortest transformation
hit -> hot  -> dot  -> dog -> cog (done)
                    -> lot -> log
            ->        

1. how to find transformation
map all posibilities
[h*t] = hit, hot

hit -> hot
*it    *ot
h*t    h*t (matched)
hi*    ho*

2. From the beginword BFS search (find posibilities)
add in queue
and put it in visited
q: hit(1)
visited: hit
q: hot(2)
visited: hit, hot
q: dot(3) lot(3)
visited: hit, hot, dot, lot ...

Quick code

if (wordList.size() < 2) return 0;

// 1. store transformation in map
unordered_map<string> transformed;
for (auto &s : wordList) {
    for (int i=0; i<s.size(); ++i) {
        auto ts = s;
        ts[i] = "*";
        transformed[ts] = s;
    }
}

// 2. BFS to find shortest transformation sequence
queue<pair<string, int>> q;
q.push(beginWord);

unordered_set<string> v;
v.insert(beginWord);

while (!q.empty())
    auto s = q.top().first;
    auto l = q.top().second;
    q.pop();
    
    for (int i=0; i<s.size(); ++i) {
        auto ts = s;
        ts[i] = "*";
        if (transformed.find(ts) != transformed.end()) {
            auto nextWords = transformed[ts];
            for (auto nextWord : nextWords) {
                if (transformed[nextWord] == endWord) return l + 1;
                if (v.find(nextWord) == v.end())
                    v.insert(nextWord);
                    q.push({nextWord, l+1});
            }
        }
    }

return 0;

**/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size() < 1) return 0;

        auto n = beginWord.size();
        // 1. store transformation in map
        unordered_map<string, vector<string>> transformed;
        for (auto &s : wordList) {
            for (int i=0; i<n; ++i) {
                auto ts = s;
                ts[i] = '*';
                transformed[ts].push_back(s);
            }
        }

        // 2. BFS to find shortest transformation sequence
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> v;
        v.insert(beginWord);

        while (!q.empty()) {
            auto f = q.front();
            auto s = f.first;
            auto l = f.second;
            q.pop();

            for (int i=0; i<n; ++i) {
                auto ts = s;
                ts[i] = '*';
                if (transformed.find(ts) != transformed.end()) {
                    auto nextWords = transformed[ts];
                    for (auto &nextWord : nextWords) {
                        if (nextWord == endWord) return l + 1;
                        if (v.find(nextWord) == v.end()) {
                            v.insert(nextWord);
                            q.push({nextWord, l+1});
                        }
                    }
                }
            }
        }

        return 0;
    }
};

int main()
{
    auto input1 = vector<string> {"hot","dot","dog","lot","log","cog"};
    assert(Solution().ladderLength("hit", "cog", input1)
        == 5);
    auto input2 = vector<string> {"hot","dot","dog","lot","log"};
    assert(Solution().ladderLength("hit", "cog", input2)
        == 0);
    return 0;
}