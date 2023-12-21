/*
https://leetcode.com/problems/candy

Solution1. Iterate Left and Right to add candy if needed
time: o(n)
space: o(n)

Solution2. (TODO) Improve solution1 without extra space
time: o(n)
space: o(1)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> c(n, 1);
        for (int i=1; i<n; ++i)
            if (ratings[i-1] < ratings[i]) c[i] = c[i-1] + 1;

        int res = 0;
        for (int i=n-2; ~i; --i) {
            if (ratings[i] > ratings[i+1]) c[i] = max(c[i], c[i+1] + 1);
            res += c[i];
        }
        res += c[n-1];
        return res;
    }
};