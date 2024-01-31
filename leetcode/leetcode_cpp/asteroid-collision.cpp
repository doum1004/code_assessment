/*
https://leetcode.com/problems/asteroid-collision

1. list to store and compare
time: o(n)
space: o(n)
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (auto value : asteroids) {
            bool add = true;
            while (!res.empty() && res.back() > 0 && value < 0 && add) {           
                add = res.back() < abs(value);
                if (res.back() <= abs(value)) res.pop_back();
            }

            if (add) res.push_back(value);
        }
        return res;
    }
};