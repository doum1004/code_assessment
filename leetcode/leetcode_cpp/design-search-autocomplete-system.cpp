#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/design-search-autocomplete-system/

//Solution1. Build Trie. And BSF to save autocomplete list in cache
//time for build trie: o(N). build trie(n*L)L:length of sentence
//time for autocomplete: o(N+M). N:depth to cur node. M: all decendent children
//space: o(N+M). N: trie, M: recursion

*/

class Trie {
public:
    Trie() {
        needToUpdate = true;
    }
    
    ~Trie() {
        for (auto &n:children) delete n.second;
    }
    
    void addWord(string &s, int time) {
        auto trie = this;
        for (auto &c:s) {
            if (trie->children[c] == nullptr) trie->children[c] = new Trie();
            trie = trie->children[c];
            //trie->counter[s] += time;
            trie->needToUpdate = true;
        }
        trie->s = s;
        trie->count += time;
    }
    
    struct maxHeap_comp{
        bool operator() (const pair<string,int> &a, const pair<string,int> &b) {
            return (a.second == b.second) ? a.first > b.first : a.second < b.second;
        }
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, maxHeap_comp> q;
    
    void buildHeap(Trie* node) { // BFS
        if (node == this) q = priority_queue<pair<string, int>, vector<pair<string, int>>, maxHeap_comp>();
        if (node && node->s != "") {
            q.push({node->s, node->count});
        }
        for (auto &child:node->children) {
            buildHeap(child.second);
        }
    }
    
    vector<string> autoCompletation() {
        if (needToUpdate) {
            buildHeap(this);

            cache.clear();
            while (!q.empty() && cache.size() < 3) {
                cache.push_back(q.top().first);
                q.pop();
            }
            needToUpdate = false;
        }
        return cache;
    }
    
    unordered_map<char, Trie*> children;
    string s;
    int count;
    bool needToUpdate;
    
    //unordered_map<string,int> counter;
    
    vector<string> cache;
};

class AutocompleteSystem {    
public:
    AutocompleteSystem() {
        root = nullptr;
        cur = nullptr;
    }
    
    ~AutocompleteSystem() {
        if (root) delete root;
    }
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Trie();
        for (int i=0; i<sentences.size(); ++i) {
            root->addWord(sentences[i], times[i]);
        }
        cur = root;
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            cur = root;
            root->addWord(keyword, 1);
            keyword = "";
            return {};
        }
        keyword += c;
        if (cur != NULL) cur = cur->children[c];
        return (cur != NULL) ? cur->autoCompletation() : vector<string>();
    }
    Trie *root;
    Trie *cur;
    string keyword;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

int main()
{
    auto input1_1 = vector<string> {"i love you","island","iroman","i love leetcode"};
    auto input1_2 = vector<int> {5,3,2,2};
    auto autoCompleteSystem = AutocompleteSystem(input1_1, input1_2);
    assert(autoCompleteSystem.input('i') == (vector<string>{"i love you","island","i love leetcode"}));
    assert(autoCompleteSystem.input(' ') == (vector<string>{"i love you","i love leetcode"}));
    assert(autoCompleteSystem.input('a') == (vector<string>{}));
    assert(autoCompleteSystem.input('#') == (vector<string>{}));
    assert(autoCompleteSystem.input('i') == (vector<string>{"i love you","island","i love leetcode"}));
    assert(autoCompleteSystem.input(' ') == (vector<string>{"i love you","i love leetcode","i a"}));
    assert(autoCompleteSystem.input('a') == (vector<string>{"i a"}));
    assert(autoCompleteSystem.input('#') == (vector<string>{}));
    assert(autoCompleteSystem.input('i') == (vector<string>{"i love you","island","i a"}));
    assert(autoCompleteSystem.input(' ') == (vector<string>{"i love you","i a","i love leetcode"}));
    assert(autoCompleteSystem.input('a') == (vector<string>{"i a"}));
    assert(autoCompleteSystem.input('#') == (vector<string>{}));

    return 0;
}