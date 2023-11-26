/*
https://leetcode.com/problems/implement-trie-prefix-tree

Solution. Build Tries in place (array, hashmap). 
time
- insert: o(n)
- search: o(n)
- startWith: o(n)
space: o(n)

*/
class Trie {
public:
    Trie() {        
    }
    
    void insert(string word) {
        Trie* node = this;
        for (auto c : word) {
            c -= 'a';
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isLeaf = true;        
    }
    
    bool search(string word) {
        Trie* node = this;
        for (auto c : word) {
            c -= 'a';
            if (!node->children[c]) return false;
            node = node->children[c];
        }
        return node->isLeaf;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto c : prefix) {
            c -= 'a';
            if (!node->children[c]) return false;
            node = node->children[c];
        }
        return true;
    }

    Trie* children[26] = {};
    bool isLeaf = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */