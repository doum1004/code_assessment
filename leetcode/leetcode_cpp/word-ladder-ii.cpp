#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/word-ladder-ii/

//Soltuion1. DSF
//time: o(n*m). build dict(n*m) + DSF(n*m)
//space: o(n*m). dict(n*m) + recursion(n*m) + visited(n). except ans

//Soltuion2. BSF would be better for shortest path
//time: o(n*m). build dict(n*m) + DSF(n*m)
//space: o(n*m). dict(n*m) + queue(n) + visited(n)

1. Make wordList dictionary for finding availibilities
ex)
*ot: hot, dot, lot
h*t: hot
ho*: hot

2. Start search from hit (DSF or BSF. But BSF would be better for shortest path finding). And store visited path.
3. When transformed result meet cog. store visited path 

//Solution3. BSF(gen next children) + DSF(generate ladder)
https://leetcode.com/problems/word-ladder-ii/discuss/241927/C%2B%2B-BFS-%2B-DFS
//time: o(n*m*26). build dict(n) + BSF_buildChildren(n*m*26) + DSF_buildLadders(n)
//space: o(n). dict(n). children(n)

1. set dict set
2. BSF to gen next and children map from current
3. If next children has endWord, build ladders (DSF)
4. Else swap (cur, next)

*/

class Solution {
public:
    unordered_map<string, vector<string>> buildDictionary(vector<string> &wordList, string &endWord, bool& goodToGo) {
        unordered_map<string, vector<string>> dict;
        goodToGo = false;
        for (auto &word:wordList) {
            if (!goodToGo) goodToGo = word == endWord;
            for (int i=0; i<word.size(); ++i) {
                auto copiedWord = word;
                copiedWord[i] = '*';
                dict[copiedWord].push_back(word);
            }
        }
        return dict;
    }
    
    int shortestPath = INT_MAX;
    void findLadders_DSF(string word, string endWord, unordered_map<string, vector<string>>& dict, vector<string>& path, unordered_set<string>& visited, vector<vector<string>>& ans) {
        // only store for shortest
        if (path.size() >= shortestPath) {
            return;
        }
        path.push_back(word);
        visited.insert(word);
        
        if (word == endWord) {
            int l = path.size();
            shortestPath = min(l, shortestPath);
            ans.push_back(path);  
        }
        else {
            for (int i=0; i<word.size(); ++i) {
                auto copiedWord = word;
                copiedWord[i] = '*';
                if (dict.count(copiedWord)) {
                    for (auto &adj:dict[copiedWord]) {
                        if (visited.count(adj)) continue;
                        
                        findLadders_DSF(adj, endWord, dict, path, visited, ans);
                    }
                }
            }
        }
        path.pop_back();
        visited.erase(word);
    }
    
    vector<vector<string>> findLadders_DSF(string beginWord, string endWord, vector<string>& wordList) {
        bool goodToGo = false;
        auto dict = buildDictionary(wordList, endWord, goodToGo);
        if (!goodToGo) return {};
        
        vector<string> path;
        unordered_set<string> visited;
        vector<vector<string>> res;
        findLadders_DSF(beginWord, endWord, dict, path, visited, res);
        for (int i=res.size()-1; i>=0; --i) {
            if (res[i].size() > shortestPath)
                res.erase(res.begin() + i);
        }
        return res;
    }
    
    vector<vector<string>> findLadders_BSF(string beginWord, string endWord, vector<string>& wordList) {
        bool goodToGo = false;
        auto dict = buildDictionary(wordList, endWord, goodToGo);
        if (!goodToGo) return {};
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        unordered_set<string> visited;
        
        int shortestPath = INT_MAX;
        vector<vector<string>> res;
        while (!q.empty()) {
            //cout << "Check time" << endl;
            int q_size = q.size();
            for (int i=0; i<q_size; ++i) {
                auto path = q.front();
                q.pop();
                
                if (path.size() > shortestPath) continue;
                    
                auto word = path.back();
                visited.insert(word);
                    
                if (word == endWord) {
                    shortestPath = min(shortestPath, (int)path.size());
                    res.push_back(path);
                }
                else if (shortestPath == INT_MAX) {
                    for (int i=0; i<word.size(); ++i) {
                        auto t = word[i];
                        word[i] = '*';
                        if (dict.count(word)) {
                            for (auto &adj:dict[word]) {
                                if (visited.count(adj)) continue;

                                vector<string> newpath = path;
                                newpath.push_back(adj);
                                q.push(newpath);
                            }
                        }
                        word[i] = t;
                    }
                }
            }
        }
        return res;
    }
    
    void buildLadders(string& word, string& endWord, unordered_map<string, vector<string>>& children, vector<string>& ladder, vector<vector<string>>& res) {
        if (word == endWord) {
            res.push_back(ladder);
        }
        else {
            for (auto& child:children[word]) {
                //cout << child << endl;
                ladder.push_back(child);
                buildLadders(child, endWord, children, ladder, res);
                ladder.pop_back();
                //cout << endl;
            }
        }
    }
    
    vector<vector<string>> findLadders_BFS_DFS(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), current, next;
        if (!dict.count(endWord)) return {};
        
        vector<vector<string>> res;
        
        current.insert(beginWord);
        vector<string> ladder;
        ladder.push_back(beginWord);
        
        unordered_map<string, vector<string>> children;
        while (true) {
            for (auto &word:current) {
                dict.erase(word);
            }
            
            // build children and next
            for (auto &parent:current) {
                auto word = parent;
                for (int j=0; j<word.size(); ++j) {
                    auto t = word[j];
                    for (int k=0; k<26; ++k) {
                        word[j] = 'a' + k;
                        if (dict.count(word)) {
                            next.insert(word);
                            children[parent].push_back(word);
                            //cout << word << endl;
                        }
                    }
                    word[j] = t;
                }
            }
            //cout << "... " << next.size() << endl;
            if (next.empty()) break;
            
            if (next.count(endWord)) {
                buildLadders(beginWord, endWord, children, ladder, res);
                //break;
            }
            
            current.clear();
            swap(current, next);
        }
        
        return res;
    }
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //return findLadders_DSF(beginWord, endWord, wordList);
        //return findLadders_BSF(beginWord, endWord, wordList);
        return findLadders_BFS_DFS(beginWord, endWord, wordList);
    }
};

int main()
{
    auto input1 = vector<string> {"hot","dot","dog","lot","log","cog"};
    auto output1 = vector<vector<string>> {{"hit","hot","dot","dog","cog"},{"hit","hot","lot","log","cog"}};
    assert(Solution().findLadders("hit", "cog", input1) == (output1));
        
    auto input2 = vector<string> {"hot","dot","dog","lot","log"};
    auto output2 = vector<vector<string>>();
    assert(Solution().findLadders("hit", "cog", input2) == (output2));
    
    return 0;
}