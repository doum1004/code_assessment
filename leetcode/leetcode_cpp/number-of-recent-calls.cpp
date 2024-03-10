/*
https://leetcode.com/problems/number-of-recent-calls

1. Queue and pop out of range
time: o(n)
space: o(n)
*/
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t); // logn
        while (q.front() < t - 3000) q.pop(); // n
        return q.size();
    }

    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */