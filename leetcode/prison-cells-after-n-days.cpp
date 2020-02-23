#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/prison-cells-after-n-days/

ex) 1 0 1 -> 0 1 0 -> 0 0 0 -> 0 1 0

// Solution1. Iterate cells for new data for N days
// time: o(C*N). C(number of cells) N days
// space: o(C). C(number of cells)

// Solution2. Find cycle
// time: o(C*Cycle)
// space: o(C). vector for cur, and first

// Solution3. DP with bitmanipulation
// time: o(C*Cycle)
// space: o(Cycle). dp for Cycle N day state

*/

class Solution {
public:
    vector<int> prisonAfterNDays_solution1(vector<int>& cells, int N) {
        if (cells.size() < 1 || N < 1) return cells;
        
        int n = cells.size();
        vector<int> cur(n, 0);
        
        for (int day=1; day<=N; ++day) {
            for (int i=1; i<n-1; ++i) {
                cur[i] = cells[i-1] == cells[i+1] ? 1 : 0;
            }
            
            cells = cur;
        }
        
        return cur;
    }
    
    vector<int> prisonAfterNDays_cycle(vector<int>& cells, int N) {
        if (cells.size() < 1 || N < 1) return cells;
        
        int n = cells.size();
        vector<int> cur(n, 0), first;
        
        int cycle=0;
        while (N-- > 0) {
            for (int i=1; i<n-1; ++i) {
                cur[i] = cells[i-1] == cells[i+1] ? 1 : 0;
            }
            if (first.empty()) first = cur;
            else if (first == cur) N %= cycle;
            
            cycle++;
            cells = cur;
        }
        
        return cur;
    }
    
    vector<int> prisonAfterNDays_dp_bitmanip(vector<int>& cells, int N) {
        if (cells.size() < 1 || N < 1) return cells;
        
        int n = cells.size();
        int state = hash(cells);
        
        unordered_map<int, int> dp;
        while (N > 0) {
            if (dp.find(state) != dp.end()) {
                int cycle = dp[state] - N;
                N %= cycle;
            }
            else {
                dp[state] = N;
            }
            
            if (N>=1) {
                state = nextDay(state, n);
                N--;
            }
        }
        
        return decodeHash(state, n);
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        //return prisonAfterNDays_solution1(cells, N);
        return prisonAfterNDays_cycle(cells, N);
        //return prisonAfterNDays_dp_bitmanip(cells, N);
    }
    
private:
    int nextDay(int state, int n) {
        int nextday=0;
        for (int i=1; i<n-1; ++i) {
            if ((state >> (i-1) & 1) == (state >> (i+1) & 1))
                nextday ^= 1 << i;
        }
        
        return nextday;
    }
    
    int hash(vector<int>& cells) {
        int state=0;
        for (int i=0; i<cells.size(); ++i) {
            if (cells[i] > 0) state ^= 1 << i;
        }
        
        return state;
    }
    
    vector<int> decodeHash(int state, int n) {
        vector<int> res(n, 0);
        for (int i=0; i<n; ++i) {
            if (state >> i & 1) res[i] = 1;
        }
        return res;
    }
};

int main()
{
    auto input = vector<int> {0,1,0,1,1,0,0,1};
    auto output = vector<int> {0, 0, 1, 1, 0, 0, 0, 0};
    assert(Solution().prisonAfterNDays(input, 7) == (output));

    return 0;
}