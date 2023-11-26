/*
https://leetcode.com/problems/combinations

Solution. Backtracking
time: n! / (k! * (n - k)!). The number of combinations is given by this formula: C(n, k)
space: o(k)

*/
class Solution {
public:
    vector<vector<int>> ans;
    void backtacking(int n, int k, vector<int>& comb, int start) {
        if (k == comb.size()) {
            ans.push_back(comb);
            return;
        }
        
        for (int i=start; i<=n; ++i) {
            comb.push_back(i);
            backtacking(n, k, comb, i+1);
            comb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        backtacking(n, k, comb, 1);
        return ans;        
    }
};