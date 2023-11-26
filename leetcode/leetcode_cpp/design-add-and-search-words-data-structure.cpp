/*
Solution1. In place array

Time:
addWord: o(n) N is the length of the word being added
search(string word): o(m) M is the total number of nodes in the Trie.
Space: O(M), where M is the total number of nodes in the Trie
*/

class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        for (auto c : word) {
            c -= 'a';
            if (!node->children[c]) node->children[c] = new WordDictionary();
            node = node->children[c];
        }
        node->isLeaf = true;        
    }
    
    bool search(string word) {
        return find(word, 0);
    }

    bool find(string word, int i) {
        if (i >= word.size()) return isLeaf;
        auto c = word[i];
        if (c != '.') {
            c -= 'a';
            if (!children[c]) return false;
            return children[c]->find(word, i+1);
        }

        for (auto child : children) {
            if (child && child->find(word, i+1))
                return true;
        }
        return false;
    }

    WordDictionary* children[26] = {};
    bool isLeaf = false;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */