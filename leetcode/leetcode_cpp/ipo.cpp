/*
https://leetcode.com/problems/ipo

Soltuion1. Brute force
time: o(n^3)
space: o(1)

Solution2. max heap
time: o(nlogn) nlogn + klogn
space: o(n) n + n
vector<pair<captial, profit>> v; sort for captial <= w
priority_queue<int> max heap to get most profits
*/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i=0; i<n; ++i) projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end());

        int i = 0;
        priority_queue<int> pq;
        while (k--) {
            while (i<n && projects[i].first <= w) {
                pq.push(projects[i].second);
                i += 1;
            }
            if (pq.empty()) break;
            w += pq.top(); pq.pop();
        }
        return w;  
    }
};