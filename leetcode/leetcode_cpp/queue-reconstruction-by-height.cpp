#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/queue-reconstruction-by-height/

// Solution1. sort(by h(desc) and k(asc)) and insert
// time: o(nlogn) : sort(nlogn) + (iteration(n) * insertion(n))
// space: o(n) : ans
1. sort by h(desc) and k(asc)
2. insert it on k
h:k
7:0 4:4 7:1 5:0 6:1 5:2
7:0 7:1 6:1 5:0 5:2 4:4

7:0
7:0 7:1
7:0 6:1 7:1
5:0 7:0 6:1 7:1
5:0 7:0 5:2 6:1 7:1
5:0 7:0 5:2 6:1 4:4 7:1

// Solution2. sort(by h(desc) and k(asc)) and insert
// time: o(n^2) : sort + (iterate * find kth position)
// space: o(n)
1. sort by h(desc) and k(asc)
2. put it on kth empty element

h:k
7:0 4:4 7:1 5:0 6:1 5:2
4:4 5:2 5:0 6:1 7:1 7:0
[][][][][4:4][]
[5:0][][5:2][][4:4][]
[5:0][][5:2][6:1][4:4][]
[5:0][7:0][5:2][6:1][4:4][7:1]

// Solution3: soluiton 2 + binary indexed tree with bin search
// time o(nlogn) : sort(nlogn) + bin indexed tree update(nlogn)
// space o(1)
// ... todo
// https://www.youtube.com/watch?v=CWDQJGaN1gY
// https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89342/O(nlogn)-Binary-Index-Tree-C%2B%2B-solution
// https://leetcode.com/problems/queue-reconstruction-by-height/discuss/427157/Three-different-C%2B%2B-solutions.-from-O(n2)-to-O(nlogn).-faster-than-99.

*/

class Solution {
public:
    vector<vector<int>> reconstructQueue_sort1(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        
        vector<vector<int>> ans;
        for (auto &p:people) {
            ans.insert(ans.begin() + p[1], p);
        }
        
        return ans;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        return reconstructQueue_sort1(people);
    }
};

int main()
{
    auto input1 = vector<vector<int>>();
    input1.push_back({7,0});
    input1.push_back({4,4});
    input1.push_back({7,1});
    input1.push_back({5,0});
    input1.push_back({6,1});
    input1.push_back({5,2});
    auto expect1 = vector<vector<int>>();
    expect1.push_back({5,0});
    expect1.push_back({7,0});
    expect1.push_back({5,2});
    expect1.push_back({6,1});
    expect1.push_back({4,4});
    expect1.push_back({7,1});
    assert(Solution().reconstructQueue(input1)
        == (expect1));

    return 0;
}
