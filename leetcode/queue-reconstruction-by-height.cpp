#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/queue-reconstruction-by-height/

// Solution1. sort and iterate to make list comparing k
// time: o(n ^ 2) : (n*k) n * number of k (up to n)
// space: o(n) : output
1. sort by k(asc) and then h(des) later
sort(nlogn)
[7,0] [5,0] [7,1] [6,1] [5,2] [4,4]

2. iterate ppl and put them in a list comparing k
o(n*k)
5 7 5 6 4 7

// Solution2. Simular to solution1. sort(h(desc) and k(asc)). and iterate to put it in index from k
// time: o(n^2) : o(n * k) k up to n
// space: o(n) : output
1. sort by h(desc) and k(asc)
[7,0] [7,1] [6,1] [5,0] [5,2] [4,4]

2. iterate and put list index[k]
7
7 7
7 6 7
5 7 5 6 4 7



*/

class Solution {
public:
    vector<vector<int>> reconstructQueue_solution1(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        
        sort(people.begin(), people.end(), [&](auto &a, auto &b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });
        
        for (auto &p : people) {
            int i;
            auto count = 0;
            for (i = 0; i<ans.size() && count < p[1]; ++i) {
                if (ans[i][0] >= p[0]) count++;
            }
            
            ans.insert(ans.begin() + i, p);
        }
        
        return ans;
    }
    
    vector<vector<int>> reconstructQueue_solution2(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        
        sort(people.begin(), people.end(), [&](auto &a, auto &b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        
        for (auto &p : people) {
            ans.insert(ans.begin() + p[1], p);
        }
        
        return ans;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //return reconstructQueue_solution1(people);
        return reconstructQueue_solution2(people);
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
