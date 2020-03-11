#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/**
https://leetcode.com/problems/search-suggestions-system/

//Solution1. Sort and bin search
//time:o(nlogn+Llogn)
//space:o(1): answer(logn)

//Solution2. Trie and build suggestion by BSF
//time: o(N+M). N(total length) + M(total decendents)
//space: o(N+M)
1. build trie (with array or map. array goes faster)
2. visit node by prefix and build suggestion by BSF (less space)

//Solution3. Trie and build suggestion by cache (trade off)
//time: o(N)
//space: o(N+M^2)
1. build trie (with array or map. array goes faster)
1.1 add cache which can see all list of words from the node
2. visit node by prefix and build suggestion by cache (faster)

*/

class Trie {
public:
    Trie() {
        fill_n(children, 26, nullptr);
    }
    
    ~Trie() {
        //for (int i=0; i<26; ++i) if(children[i]) delete children[i];
        //for (auto &n:children) delete n.second;
    }
    
    void addWord(string &word) {
        auto trie = this;
        for (auto &c:word) {
            auto i = c - 'a';
            if (!trie->children[i]) trie->children[i] = new Trie();
            trie = trie->children[i];
            //if (!trie->children.count(c)) trie->children[c] = new Trie();
            //trie = trie->children[c];
            trie->cache.push_back(word);
        }
        trie->s = word;
    }
    
    void buildSuggestion(Trie* node, priority_queue<string, vector<string>, greater<void>>& q) {
        if (!node) return;
        
        for (int i=0; i<26; ++i) {
            if (!node->children[i]) continue;
            buildSuggestion(node->children[i], q);
        }
        //for (auto &c:node->children) {
        //    buildSuggestion(c.second, q);
        //}
        
        if (node->s != "") q.push(node->s);
    }
    
    vector<string> suggestionBSF() {
        priority_queue<string, vector<string>, greater<void>> q;
        buildSuggestion(this, q);
        
        vector<string> res;
        for (int i=1; i<=3; ++i) {
            if (q.empty()) break;
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
    
    vector<string> suggestionCache() {
        sort(cache.begin(), cache.end());
        
        vector<string> res;
        for (int i=0; i<3; ++i) {
            if (cache.size() < i+1) break;
            res.push_back(cache[i]);
        }
        return res;
    }
    
    vector<string> suggestion() {
        //return suggestionBSF();
        return suggestionCache();
    }
    
    Trie* child(char& c) {
        //return children.count(c) ? children[c] : nullptr;
        return children[c - 'a'];
    }
    
    Trie* children[26];
    //unordered_map<char, Trie*> children;
    string s;
    
    vector<string> cache;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts_trie(vector<string>& products, string& searchWord) {
        auto root = new Trie(); 
        for (auto &p:products) {
            root->addWord(p);
        }
        
        vector<vector<string>> res;
        
        auto cur = root;
        for (auto &c:searchWord) {
            if (cur) cur = cur->child(c);
            
            if (cur) {
                res.push_back(cur->suggestion());
            }
            else {
                res.push_back({});
            }
        }
        delete root;
        return res;
    }
    
    vector<vector<string>> suggestedProducts_sort(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string cur = "";
        
        auto it = products.begin();
        for (auto &c:searchWord) {
            cur += c;
            vector<string> suggested;
            it = lower_bound(it, products.end(), cur);
            for (int i=0; i<3 && it+i != products.end(); ++i) {
                string& s = *(it + i);
                if (s.find(cur)) break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        return suggestedProducts_sort(products, searchWord);
        //return suggestedProducts_trie(products, searchWord);
    }
};

int main()
{
    auto input1 = vector<string> {"mobile","mouse","moneypot","monitor","mousepad"};
    auto input2 = "mouse";
    auto output1 = vector<vector<string>> {{"mobile","moneypot","monitor"},{"mobile","moneypot","monitor"},{"mouse","mousepad"},{"mouse","mousepad"},{"mouse","mousepad"} };
    auto ans = Solution().suggestedProducts(input1, input2);
    assert(Solution().suggestedProducts(input1, input2) == (output1));

    return 0;
}
