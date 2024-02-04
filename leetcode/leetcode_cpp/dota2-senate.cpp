/*
https://leetcode.com/problems/dota2-senate

1. Queue
time: o(n)
space: o(n)
*/
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r1;
        queue<int> d1;
        int n = senate.size();
        for (int i=0; i<senate.size(); ++i) {
            if (senate[i] == 'R') r1.push(i);
            else d1.push(i);
        }

        while (!r1.empty() && !d1.empty()) {
            if (r1.front() < d1.front()) r1.push(n);
            else d1.push(n);
            n += 1;
            r1.pop(); d1.pop();
        }
        return r1.empty() ? "Dire" : "Radiant";
    }
};