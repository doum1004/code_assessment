/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

/*
https://leetcode.com/problems/construct-quad-tree

Solution1. Divide and Conquer (recursion)
time: o(n^2logn)
space: o(logn)
*/

class Solution {
public:
    bool isAllSame(vector<vector<int>>& grid, int x, int y, int n) {
        int val = grid[x][y];
        for (int i=x; i<x+n; ++i) {
            for (int j=y; j<y+n; ++j) {
                if (val != grid[i][j])
                    return false;
            }
        }
        return true;
    }
    Node* build(vector<vector<int>>& grid, int x, int y, int n) {
        if (isAllSame(grid, x, y, n))
            return new Node(grid[x][y], true);

        n /= 2;
        Node* node = new Node(true, false);
        node->topLeft = build(grid, x, y, n);
        node->topRight = build(grid, x, y+n, n);
        node->bottomLeft = build(grid, x+n, y, n);
        node->bottomRight = build(grid, x+n, y+n, n);
        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        return build(grid,0,0,grid.size());
    }
};