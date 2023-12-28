#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/word-ladder-ii

// time complexcity
https://www.quora.com/What-is-the-time-complexity-of-Word-Ladder-II

//Soltuion1. DSF

//Soltuion2. BSF would be better for shortest path
//time: o(b^d). b(branch factor) ^ d(depth). ?
//space: o(b^d). dict(b^d) + queue(n) + visited(n). ?

1. Make wordList dictionary for finding availibilities
ex)
*ot: hot, dot, lot
h*t: hot
ho*: hot

2. Start search from hit (DSF or BSF. But BSF would be better for shortest path finding). And store visited path.
3. When transformed result meet cog. store visited path 

//Solution3. BSF(gen next children) + DSF(generate ladder)
//time: o(n*L*26 + nlogn). build next (n*L*26) + build ladder (L*M == L*2^L == nlogn) O(L*M), where L is the length of the shortest path and M is the number of possible shortest paths.
//space:? o(n). graph(n) + children(n) + buildnext(n)

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
    
    void buildLadder(string& beginWord, string& endWord, unordered_map<string, vector<string>>& children, vector<string>& path, vector<vector<string>>& res) {
        path.push_back(beginWord);
        if (beginWord == endWord) {
            res.push_back(path);
        }
        else {
            for (auto &c:children[beginWord]) {
                buildLadder(c,endWord,children,path,res);
            }
        }
        path.pop_back();
    }
    
    vector<vector<string>> findLadders_BFS_DFS(string& beginWord, string& endWord, vector<string>& wordList) {
        unordered_set<string> g(wordList.begin(), wordList.end()); // graph(n)
        if (!g.count(endWord)) return {};
        
        unordered_set<string> cur, next;
        cur.insert(beginWord);
        
        unordered_map<string, vector<string>> children;
        vector<vector<string>> res;
        while (cur.size()) {
            for (auto &s:cur) { // filter for next
                g.erase(s);
            }
            
            for (auto &s:cur) { // build next (n*26*wordLength)
                for (auto i=0; i<s.size(); ++i) { 
                    auto copied_s = s;
                    for (auto j=0; j<26; ++j) {
                        copied_s[i] = 'a' + j;
                        if (g.count(copied_s)) {
                            next.insert(copied_s);
                            children[s].push_back(copied_s);
                        }
                    }
                }
            }
            
            if (next.count(endWord)) {
                vector<string> path;
                buildLadder(beginWord, endWord, children, path, res); // DFS O(L*M), where L is the length of the shortest path and M is the number of possible shortest paths.
            }
            
            cur.clear();
            swap(cur, next);
        }
        
        return res;
    }
    
    void help(const string& s, unordered_map<string, pair<int, unordered_set<string>>>& m, vector<vector<string>>& res, vector<string>& sofar) {
        sofar.push_back(s);
        if (m[s].second.size() == 0) res.push_back(sofar);
        else for (const string& str : m[s].second) help(str, m, res, sofar);
        sofar.pop_back();
    }

    vector<vector<string>> findLadders_bfs_dfs_latest(string& beginWord, string& endWord, vector<string>& wordList) {
        unordered_map<string, pair<int, unordered_set<string>>> m;
        for (const string& s : wordList) m[s] = {0, {}};

        m[beginWord] = {1, {}};

        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {
            string word = q.front(); q.pop();
            int dist = m[word].first;
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (m.count(temp) && temp != word) {
                        if (m[temp].first == dist + 1) m[temp].second.insert(word);
                        else if (m[temp].first == 0 || m[temp].first > dist + 1) {
                            m[temp].first = dist + 1;
                            m[temp].second.clear();
                            m[temp].second.insert(word);
                            if (temp != endWord) q.push(temp);
                        }
                    } 
                }
            }
        }
        if (m[endWord].first == 0) return {};
        vector<vector<string>> res;
        vector<string> sofar;
        help(endWord, m, res, sofar);
        for (auto& v : res) reverse(v.begin(), v.end());
        return res;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //return findLadders_DSF(beginWord, endWord, wordList);
        //return findLadders_BSF(beginWord, endWord, wordList);
        //return findLadders_BFS_DFS(beginWord, endWord, wordList);
        return findLadders_bfs_dfs_latest(beginWord, endWord, wordList);
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