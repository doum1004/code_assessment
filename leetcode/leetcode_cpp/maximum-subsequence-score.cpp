/*
https://leetcode.com/problems/maximum-subsequence-score

1. Sort + Heap
time: o(nlogn)
space: o(n)
*/
class Solution {
public:
    long long maxScore(vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v(speed.size());
        for (int i=0; i<speed.size(); ++i) v[i] = { efficiency[i], speed[i] };
        sort(rbegin(v), rend(v)); // nlogn

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long res = INT_MIN;
        for (auto& values : v) { // n
            if (pq.size() == k) {
                sum -= pq.top();
                pq.pop();
            }
            pq.push(values.second); // logn
            sum += values.second;
            if (pq.size() >= k)
                res = max(res, sum * values.first);
        }
        return res;
    }
};