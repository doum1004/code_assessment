#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/word-search-ii

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
    Trie() { m = vector<Trie*>(26, nullptr); }
    ~Trie() {
        for (auto v : m) delete v;
        m.clear();
    }

    void addWord(string& word) {
        auto cur = this;
        for (auto c:word) {
            int idx = c - 'a';
            if (!cur->m[idx]) cur->m[idx] = new Trie();
            cur = cur->m[idx];
        }
        cur->isWord = true;
    }
    vector<Trie*> m;
    bool isWord = false;
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, Trie* node, string& cur, vector<string>& res) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*') return;
        node = node->m[board[i][j] - 'a'];
        if (!node) return;

        auto t = board[i][j];
        cur.push_back(t);

        board[i][j] = '*';
        if (node->isWord) {
            res.push_back(cur);
            node->isWord = false;
        }
        dfs(board, i - 1, j, node, cur, res);
        dfs(board, i, j - 1, node, cur, res);
        dfs(board, i + 1, j, node, cur, res);
        dfs(board, i, j + 1, node, cur, res);

        board[i][j] = t;
        cur.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for (auto& word: words) {
            root->addWord(word);
        }
        vector<string> res;
        string cur;
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                dfs(board, i, j, root, cur, res);
            }
        }
        return res;
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