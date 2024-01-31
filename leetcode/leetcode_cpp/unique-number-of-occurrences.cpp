/*
https://leetcode.com/problems/unique-number-of-occurrences

1. Using map and set
time: o(n)
space: o(n)
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (auto value : arr) m[value] += 1;
        for (auto& values : m) {
            //if (s.count(values.second)) return false;
            //s.insert(values.second);
            if (!s.insert(values.second).second) return false;
        }
        return true;
    }
};