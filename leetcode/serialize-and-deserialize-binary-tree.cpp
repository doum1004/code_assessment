#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// serialize and deserialize DSF preorder
// time: o(n) visit all nodes
// space: o(n) recursion
  1
 2 3
  4 5
1,2,#,#,3,4,#,#,5,#,#
->
1)
  1

2)
  1
 2
 
3)
  1
 2
#

4)
  1
 2
# #

5)
    1
  2  3 
 # #

6)
     1
  2    3 
 # #  #
 
7)
     1
  2    3 
 # #  # #
 
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int p = 0;
        return deserialize_(data, p);
    }
    
private:
    TreeNode* deserialize_(string &data, int &p) {
        if (p + 1 >= data.size()) return nullptr;
        if (data[p] == '#') {
            p += 2;
            return nullptr;
        }
        
        int i = data.find(",", p);
        int len = i - p;
        auto node = new TreeNode(stoi(data.substr(p, len)));
        p += len + 1;
        node->left = deserialize_(data, p);
        node->right = deserialize_(data, p);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    auto result = codec.deserialize(codec.serialize(root));
    assert(isEqual(root, result));

    return 0;
}
