#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/daily-temperatures/

// Soltuion1. Brute force (no accepted)
iterate i
    itreate j
// time o(n^2)
// space o(1)

// Solution2. linear with stack (same for other top to bottom)
// time: o(n)
// space: o(n) stack
1. iterate T
    2. if stack.top is not smaller than cur, put it in stack
    3. if top is smaller then, pop and put ans

*/

class Solution {
public:
    vector<int> dailyTemperatures_bruteforce(vector<int>& T) {
        int n = T.size();
        for (int i=0; i<n; ++i) {
            auto r = 0;
            for (int j=i+1; j<n; ++j) {
                if (T[i] < T[j]) {
                    r = j - i;
                    break;
                }
            }
            T[i] = r;
        }
        
        return T;
    }
    vector<int> dailyTemperatures_stack(vector<int>& T) {
        int n = T.size();
        stack<pair<int,int>> s;
        
        for (int i=0; i<n; ++i) {
            while (!s.empty() && s.top().first < T[i]) {
                auto cur = s.top();
                s.pop();
                T[cur.second] = i - cur.second;
            }
            s.push({exchange(T[i], 0), i}); // same as below. exchange return first one
            //s.push({T[i], i});
            //T[i] = 0;
        }
        
        return T;
    }
    
    vector<int> dailyTemperatures(vector<int>& T) {
        //return dailyTemperatures_bruteforce(T);
        return dailyTemperatures_stack(T);
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
