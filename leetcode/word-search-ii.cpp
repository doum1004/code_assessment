#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**

// Solution1. Backtracking(DSF) with Trie
// time: o( m ( 4*3^(L-1) )). m(board) L(length of word)
// space: o(w + L). w(words in tires) + L(length of word. recursion)

- backtracking: change, recursion, undo
- trie hold dictionary of words.
time: insert/search o(n)
space: o(W*L) W(number of word) L(length of word)

1. build tries from words
2. backtracking on board to find words(tries)
3. mark as visited and unmark after

*/

class Trie {
public:
    Trie()
    : exist_(false) {
        fill_n(chidlren_, 26, nullptr);
    }
    
    ~Trie() {
        for (int i=0; i<26; ++i) delete chidlren_[i];
    }
    
    void addWord(const string& word) {
        auto iter = this;
        for (int i=0; i<word.size(); ++i) {
            if (iter->chidlren_[word[i] - 'a'] == nullptr) iter->chidlren_[word[i] - 'a'] = new Trie();
            iter = iter->chidlren_[word[i] - 'a'];
        }
        iter->exist_ = true;
    }
    
    Trie** children() { return chidlren_; }

    bool exist() { return exist_; }
    
    void setExist(const bool v) { exist_ = v; }
    
private:
    Trie* chidlren_[26];
    bool exist_;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.size() < 1 || board[0].size() < 1) return vector<string>();
        
        auto root = buildTrie(words);
        
        vector<string> ans;
        string word;
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                backTrackFindWord(board, root, i, j, word, ans);
            }
        }
        
        return ans;
    }
    
private:
    Trie* buildTrie(vector<string>& words) {
        auto root = new Trie();
        for (auto &word:words) root->addWord(word);
        return root;
    }
    
    int offset[5] = {0,1,0,-1,0};
    void backTrackFindWord(vector<vector<char>>& board, Trie* node, int r, int c, string& word, vector<string>& ans) {
        if (r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c] == '*') return;
        auto temp = board[r][c];
        if (node->children()[temp - 'a'] == nullptr) return;
        
        node = node->children()[temp - 'a'];
        word.push_back(temp);
        board[r][c] = '*';
        if (node->exist()) {
            ans.push_back(word);
            node->setExist(false);
        }
        
        for (int i=0; i<=3; ++i) {
            backTrackFindWord(board, node, r+offset[i], c+offset[i+1], word, ans);
        }
        
        word.pop_back();
        board[r][c] = temp;
    }
};

int main()
{
    auto input1_1 = vector<vector<char>> {{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}};
    auto input1_2 = vector<string> {"oath","pea","eat","rain"};
    auto output = Solution().findWords(input1_1, input1_2);
    assert(find(output.begin(), output.end(), "eat") != output.end());
    assert(find(output.begin(), output.end(), "oath") != output.end());
    return 0;
}