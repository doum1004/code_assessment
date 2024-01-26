#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/daily-temperatures

Soltuion1. Brute force (no accepted)
time o(n^2)
space o(1)

Solution2. linear with stack (same for other top to bottom)
time: o(n)
space: o(n) stack
*/

class Solution {
public:
    vector<int> dailyTemperatures_bruteforce(vector<int>& temperatures) {
        int n = temperatures.size();
        for (int i=0; i<n; ++i) {
            auto r = 0;
            for (int j=i+1; j<n; ++j) {
                if (temperatures[i] < temperatures[j]) {
                    r = j - i;
                    break;
                }
            }
            temperatures[i] = r;
        }
        
        return temperatures;
    }

    vector<int> dailyTemperatures_stack(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        for (int i=0; i<temperatures.size(); ++i) {
            while (!s.empty() && s.top().first < temperatures[i]) {
                temperatures[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({exchange(temperatures[i], 0), i});
        }
        return temperatures;        
    }
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //return dailyTemperatures_bruteforce(temperatures);
        return dailyTemperatures_stack(temperatures);
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
