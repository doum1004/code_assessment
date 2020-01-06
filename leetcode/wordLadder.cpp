#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int v)
    : val(v)
    , left(nullptr)
    , right(nullptr)
    {
        
    }
    TreeNode (vector<int> vals)
    : val(-1)
    , left(nullptr)
    , right(nullptr)
    {
        auto h = false;
        auto l = false;
        queue<TreeNode*> q;
        for (auto v : vals) {
            
            if (!h)
            {
                val = v;
                h = true;
                q.push(this);
            }
            else
            {
                auto nxt = (v != -1) ? new TreeNode(v) : nullptr;
                l = !l;
                
                auto cur = q.front();
                if (!l)
                {
                    if (cur != nullptr)
                        cur->right = nxt;
                    q.pop();
                }
                else
                {
                    if (cur != nullptr)
                        cur->left = nxt;
                }
                
                q.push(nxt);
            }
        }
    }

    bool operator==(const TreeNode& r) const
    {
        auto result = val == r.val;
        result &= (left != nullptr) ? r.left != nullptr : r.left == nullptr;
        result &= (right != nullptr) ? r.right != nullptr : r.right == nullptr;
        if (result)
        {
            if (left != nullptr)
            {
                result &= *left == *r.left;
            }
            if (right != nullptr)
            {
                result &= *right == *r.right;
            }
        }
        return result;
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

int ladderLength_singleDirectional(string beginWord, string endWord, vector<string>& wordList) {
    auto n = beginWord.size();
    auto transformedWrodsMap = unordered_map<string, vector<string>>();
    for (auto &word : wordList)
    {
        for (int i=0; i<n; i++)
        {
            auto new_word = word.substr(0, i) + "*" + word.substr(i+1, n);
            vector<string> transformedWrods;
            if (transformedWrodsMap.find(new_word) != transformedWrodsMap.end()) {
                transformedWrods = transformedWrodsMap[new_word];
            }
            transformedWrods.push_back(word);
            transformedWrodsMap[new_word] = transformedWrods;
        }
    }
    
    auto q = queue<pair<string, int>>();
    q.push(pair(beginWord, 1));

    auto visited = unordered_set<string>();
    visited.insert(beginWord); // ?
    
    while (!q.empty()) {
        auto word = q.front().first;
        auto level = q.front().second;
        q.pop();
        
        for (int i=0; i<n; i++)
        {
            auto new_word = word.substr(0,i) + "*" + word.substr(i+1, n);
            if (transformedWrodsMap.find(new_word) != transformedWrodsMap.end()) {
                for (auto &found : transformedWrodsMap[new_word]) {
                    if (found == endWord) {
                        return level + 1;
                    }
                    
                    if (visited.find(found) == visited.end()) {
                        visited.insert(found);
                        q.push(pair(found, level + 1));
                    }
                }
            }
        }
    }

    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    return ladderLength_singleDirectional(beginWord, endWord, wordList);
}

int main()
{
    auto input1 = vector<string> {"hot","dot","dog","lot","log","cog"};
    assert(ladderLength("hit", "cog", input1)
        == 5);
    auto input2 = vector<string> {"hot","dot","dog","lot","log"};
    assert(ladderLength("hit", "cog", input2)
        == 0);
    return 0;
}