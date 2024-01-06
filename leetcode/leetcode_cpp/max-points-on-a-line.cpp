/*
https://leetcode.com/problems/max-points-on-a-line

Solution1. Iteration and store by slope
time: o(n^2)
space: o(n)
slope(inclination, y2-y1/x2-x1) x2-x1 -> INT_MAX
https://leetcode.com/problems/max-points-on-a-line/solutions/3016360/easiest-c-solution-with-detailed-explanation/?envType=study-plan-v2&envId=top-interview-150

*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i=0; i<n; ++i) {
            unordered_map<double, int> m;
            double x1 = points[i][0];
            double y1 = points[i][1];

            for (int j=i+1; j<n; ++j) {
                double x2 = points[j][0];
                double y2 = points[j][1];
                double dx = x2 - x1;
                double slope = 0;
                if (dx == 0) slope = INT_MAX;
                else slope = (y2-y1) / dx;
                m[slope]++;
                res = max(res, m[slope]);
            }
        }
        return res + 1;
    }
};