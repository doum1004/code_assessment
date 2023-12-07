/*
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

Solution1. Sort and Greedy (find the next and next)
time: o(n)
space: o(1)

1. sort vectors (based on vector[1])
2. iterate vectors
2.1 update arrow and ans+=1 when cur arrow is smaller than cur point[0] or first iteration

ex) [[10,16],[2,8],[1,6],[7,12]]
-> [[1,6],[2,8],[7,12],[10,16]]

arrow(6 -> 12)
1  6
 2     8
     7     12
         10   16
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(), points.end(), [](auto& a, auto& b) {
          return a[1] < b[1];
      });
      int ans = 0;
      int arrow = 0;
      for (auto& point : points) {
          if (ans == 0 || arrow < point[0]) {
              ans += 1;
              arrow = point[1];
          }
      }
      return ans;
    }
};