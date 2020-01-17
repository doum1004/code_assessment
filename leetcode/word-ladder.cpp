#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

// https://leetcode.com/problems/word-ladder/

// BFS 
// time: o(m x n) m = n.size()
// space: o(m x n)

// 1. wordlist -> set all possible
// possibleTrnasform unorderedset<str, vector<Str>>> [*bc] = abc [a*c] = abc ...
// 
// 2. queue<beginword, 1(level)>
//
// 3. visitedvalue
// visited unorderedset<str>
//
// 4. loop queue
// cur = queue.pop
// word = cur.first
// l = cur.second
//
// 5. find possible words (adjacentword)
// loop possible words
//  return l + 1 if it is end world
//  put visited
//  add in queue


// Improve -> bidirectional
// 1. wordlist -> set all possible
// possibleTrnasform unorderedset<str, vector<Str>>> [*bc] = abc [a*c] = abc ...

// 2. queue for beginword and endword
// q_begin.push(pair(begin, 1))
// q_end.push(pair(end, 1))

// 3. visitedvalue for begin and end
// visited_begin unorderedset<str>
// visited_end unorderedset<str>

// 4. loop (!q_b.empty && !q_e.empty())
// check(q_b, vsited_begin, visited_end)
// check(q_e, visited_end, visited_begin)

// 5. check will do pop queue, and return if adjacency has in other visited
// otherwise push it its visited

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto transformed = unordered_map<string, vector<string>>();

        int n = beginWord.size();
        for (auto &str : wordList) {
            for (int i=0; i<n; ++i) {
                auto s = str;
                s[i] = '*';
                transformed[s].push_back(str);                
            }
        }

        queue<pair<string, int>> q;
        q.push(pair(beginWord, 1));

        auto visited = unordered_set<string>();
        visited.insert(beginWord);

        while (!q.empty()) {
            auto cur = q.front();
            auto w = cur.first;
            auto l = cur.second;
            q.pop();

            for (int i=0; i<n; ++i) {
                auto ts = w;
                ts[i] = '*';
                if (transformed.find(ts) != transformed.end()) {
                    auto adjacencies = transformed[ts];
                    for (auto &adjacency : adjacencies) {
                        if (adjacency == endWord) return l + 1;

                        if (visited.find(adjacency) == visited.end()) {
                            visited.insert(adjacency);
                            q.push(pair(adjacency, l + 1));
                        }
                    }
                } 
            }
        }

        return 0;
    }
};

// Example 1:

// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// transformedMap = unordered_map<str, vector<str>> { (*ot, {hot, dot, lot}, (h*t, {hot}), (do*, {dot, dog}) ) }
// q = queue<pair<str, int_level>>
// visited = unordered_map<str, bool>  

// Output: 5

// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Example 2:

// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]

// Output: 0

// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

// class Solution {
//     public:
//     int visitWord(const int n, unordered_map<string, vector<string>>& transformedWords, queue<pair<string, int>>& q, unordered_map<string, int>& visited, unordered_map<string, int>& othervisited) {
//         auto word = q.front().first;
//         auto level = q.front().second;
//         q.pop();

//         for (int i=0; i<n; i++) {
//             auto new_word = word.substr(0, i) + "*" + word.substr(i+1, n);
//             if (transformedWords.find(new_word) != transformedWords.end()) {
//                 for (auto found : transformedWords[new_word]) {
//                     if (othervisited.find(found) != othervisited.end()) {
//                         return level + othervisited[found];
//                     }

//                     if (visited.find(found) == visited.end()) {
//                         visited[found] = level + 1;
//                         q.push(pair(found, level + 1));
//                     }
//                 }
//             }
//         }

//         return -1;
//     }

//     int ladderLength_bidirectional2(string beginWord, string endWord, vector<string>& wordList) {
//         if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

//         // map for transformed words
//         auto n = beginWord.size();
//         auto transformedWords = unordered_map<string, vector<string>>();
//         for (auto &word : wordList) {
//             for (int i=0; i<n; i++) {
//                 auto new_word = word.substr(0, i) + "*" + word.substr(i+1, n);
//                 vector<string> words;
//                 if (transformedWords.find(new_word) != transformedWords.end()) {
//                     words = transformedWords[new_word];
//                 }
//                 words.push_back(word);
//                 transformedWords[new_word] = words;
//             }
//         }

//         // queue for BFS
//         auto b_q = queue<pair<string, int>>();
//         b_q.push(pair(beginWord, 1));
//         auto e_q = queue<pair<string, int>>();
//         e_q.push(pair(endWord, 1));
        
//         // set for visited
//         auto b_visited = unordered_map<string, int>();
//         b_visited[beginWord] = 1;
//         auto e_visited = unordered_map<string, int>();
//         e_visited[endWord] = 1;

//         while (!b_q.empty() && !e_q.empty()) {
//             auto ans1 = visitWord(n, transformedWords, b_q, b_visited, e_visited);
//             if (ans1 > -1)
//                 return ans1;
//             auto ans2 = visitWord(n, transformedWords, e_q, e_visited, b_visited);
//             if (ans2 > -1)
//                 return ans2;
//         }

//         return 0;
//     }

//     int ladderLength_bidirectional(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> dict(wordList.begin(), wordList.end());
//         unordered_set<string> head, tail, *phead, *ptail;
//         if (dict.find(endWord) == dict.end()) {
//             return 0;
//         }

//         head.insert(beginWord);
//         tail.insert(endWord);
//         int level = 2;
//         while (!head.empty() && !tail.empty()) {
//             if (head.size() < tail.size()) {
//                 phead = &head;
//                 ptail = &tail;
//             }
//             else {
//                 phead = &tail;
//                 ptail = &head;
//             }

//             unordered_set<string> temp;
//             for (auto word : *phead) {
//                 for (int i=0; i<word.size(); i++) {
//                     auto new_word = word;
//                     for (char c = 'a'; c <= 'z'; c++) {
//                         new_word[i] = c;
//                         if (ptail->find(new_word) != ptail->end()) {
//                             return level;
//                         }
                        
//                         if (dict.find(new_word) != dict.end()) {
//                             temp.insert(new_word);
//                             dict.erase(new_word);
//                         }
//                     }
//                 }
//             }

//             level++;
//             phead->swap(temp);
//         }

//         return 0;
//     }

//     int ladderLength_singledirectional(string beginWord, string endWord, vector<string>& wordList) {
//         auto n = beginWord.size();
//         auto transformedWrodsMap = unordered_map<string, vector<string>>();
//         for (auto &word : wordList)
//         {
//             for (int i=0; i<n; i++)
//             {
//                 auto new_word = word.substr(0, i) + "*" + word.substr(i+1, n);
//                 vector<string> transformedWrods;
//                 if (transformedWrodsMap.find(new_word) != transformedWrodsMap.end()) {
//                     transformedWrods = transformedWrodsMap[new_word];
//                 }
//                 transformedWrods.push_back(word);
//                 transformedWrodsMap[new_word] = transformedWrods;
//             }
//         }
        
//         auto q = queue<pair<string, int>>();
//         q.push(pair(beginWord, 1));

//         auto visited = unordered_set<string>();
//         visited.insert(beginWord); // ?
        
//         while (!q.empty()) {
//             auto word = q.front().first;
//             auto level = q.front().second;
//             q.pop();
            
//             for (int i=0; i<n; i++)
//             {
//                 auto new_word = word.substr(0,i) + "*" + word.substr(i+1, n);
//                 if (transformedWrodsMap.find(new_word) != transformedWrodsMap.end()) {
//                     for (auto &found : transformedWrodsMap[new_word]) {
//                         if (found == endWord) {
//                             return level + 1;
//                         }
                        
//                         if (visited.find(found) == visited.end()) {
//                             visited.insert(found);
//                             q.push(pair(found, level + 1));
//                         }
//                     }
//                 }
//             }
//         }

//         return 0;
//     }

//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         return ladderLength_bidirectional(beginWord, endWord, wordList);
//         //return ladderLength_singledirectional(beginWord, endWord, wordList);
//     }
// };

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