/*
https://leetcode.com/problems/combination-sum

Solution1. Backtracking

[2 2 3 7]
0
2: 0 + 2
4: 2, 2 + 2
6: 2, 2, 2 + (pass)
4: 2, 2 + 3
7: 2,2,3 (add)
*/

class Solution {
public:
    void combinationSum(vector<int>& candidates, int target, vector<vector<int>>& ans, int sum, int startIndex, vector<int> res) {
        if (sum == target) {
            ans.push_back(res);
            return;
        }

        for (int i=startIndex; i<candidates.size(); ++i) {
            auto n = candidates[i];
            if (sum + n <= target) {
                res.push_back(n);
                combinationSum(candidates, target, ans, sum + n, i, res);
                res.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        combinationSum(candidates, target, ans, 0, 0, {});
        return ans;
    }
};