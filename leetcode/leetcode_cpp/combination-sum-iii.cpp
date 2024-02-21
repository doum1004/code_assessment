/*
https://leetcode.com/problems/combination-sum-iii

time: o(9^k)
space: o(k)
*/
class Solution {
public:
    void take(int k, int n, int begin, vector<int>& comb, vector<vector<int>>& res) {
        if (k == 0) {
            if (n == 0) res.push_back(comb);
            return;
        }
        for (int i=begin; i<=9 && i<=n; i++) {
            comb.push_back(i);
            take(k-1, n-i, i+1, comb, res);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> comb;
        take(k, n, 1, comb, res);
        return res;
    }
};