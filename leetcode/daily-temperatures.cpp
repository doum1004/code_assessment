#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/daily-temperatures/

// Soluiton1. using stack (stack can be replaced by vector)
// time: o(n)
// space: o(n) : stack(n)
73, 74, 75, 71, 69, 72, 76, 73

1. iterate n and while (!s.empty && s.top.value < n)
[0] 73
s: (73,0)

[1] 74
s: 73,0 -> 73 < 74
o: [1][0][0][0][0][0][0][0]
s: (74,1)
[2] 75
s: 74,1 -> 74 < 75
o: [1][1][0][0][0][0][0][0]
s: (75,2)
[3] 71
s: (75,2) (71,3)
[4] 69
s: (75,2) (71,3) (69,4)
[5] 72
s: (75,2) (71,3) (69,4) 69, 72
o: [1][1][0][2][1][0][0][0]

...

// Solution2. same as solution1 but reverse

*/

class Solution {
public:
    vector<int> dailyTemperatures_solution1(vector<int>& T) {
        stack<pair<int,int>> s;
        for (int i=0; i<T.size(); ++i) {
            while (!s.empty() && s.top().first < T[i]) {
                auto t = s.top();
                s.pop();
                T[t.second] = i - t.second;
            }
            s.push({exchange(T[i], 0), i}); // same as below
            //s.push({T[i], i});
            //T[i] = 0;
        }
        
        return T;
    }
    
    vector<int> dailyTemperatures_solution2(vector<int>& T) {
        stack<pair<int,int>> s;
        for (int i=T.size()-1; i>=0; --i) {
            while (!s.empty() && s.top().first <= T[i]) s.pop();
            s.push({exchange(T[i], s.empty() ? 0 : s.top().second - i), i});
        }
        return T;
    }
    
    vector<int> dailyTemperatures(vector<int>& T) {
        return dailyTemperatures_solution1(T);
        //return dailyTemperatures_solution2(T);
    }
};

int main()
{
    auto input1 = vector<int> {73, 74, 75, 71, 69, 72, 76, 73};
    auto expect1 = vector<int> {1, 1, 4, 2, 1, 1, 0, 0};
    assert(Solution().dailyTemperatures(input1)
        == (expect1));

    return 0;
}
