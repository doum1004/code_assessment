#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/course-schedule/

// solution1. Recursion DSF preorder with visited and instack
// time: o(n)
// space: o(n) : visited(n), instack(n), recursion(n)

// solution2. Iteation DSF with visited and stack
// time: o(n)
// space: o(n) : visited(n), stack(n)

1. build map for graph
2. iterate graph, init stack to start
3.  iterate stack till stack is empty
4.      if adj is not visited, add in stack to visit
5.      if adj is in stack, return it has cycle
6.      if all adjs are visited, pop node


*/

class Solution {
public:
    bool hasCycle(unordered_map<int, vector<int>>& m, unordered_set<int>& v, unordered_set<int>& instack, int node) {
        //cout << node << endl;
        v.insert(node);
        instack.insert(node);
        
        if (m.find(node) != m.end()) {
            for (auto &adj:m[node]) {
                if (v.find(adj) == v.end() && hasCycle(m, v, instack, adj)) {
                    return true;
                }
                else if (instack.find(adj) != instack.end()) {
                    return true;
                }
            }
        }
        
        instack.erase(node);
        return false;
    }
    
    bool canFinish_dsf(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        for (auto &p:prerequisites) {
            m[p[0]].push_back(p[1]);
        }
        
        unordered_set<int> v;
        unordered_set<int> instack;
        for (auto &node:m) {
            if (hasCycle(m, v, instack, node.first)) return false;
        }
        
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return canFinish_dsf(numCourses, prerequisites);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{1,0}};
    assert(Solution().canFinish(2, input1) == (true));
    auto input2 = vector<vector<int>> {{1,0},{0,1}};
    assert(Solution().canFinish(2, input2) == (false));
    return 0;
}