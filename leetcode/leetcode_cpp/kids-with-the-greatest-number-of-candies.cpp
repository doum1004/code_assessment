/*
https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
*/
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size());
        int m = 0;
        for (auto candy : candies) m = max(m, candy);
        for (int i=0; i<candies.size(); ++i) {
            res[i] = candies[i] + extraCandies >= m;
        }
        return res;
    }
};