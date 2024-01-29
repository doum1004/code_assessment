/*
https://leetcode.com/problems/smallest-number-in-infinite-set

1. Using set
time: o(logn)
space: o(n)
*/
class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i=1; i<=1000; ++i) s.insert(i);
    }
    
    int popSmallest() {
        int cur = *s.begin();
        s.erase(s.begin());
        return cur;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
    set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */