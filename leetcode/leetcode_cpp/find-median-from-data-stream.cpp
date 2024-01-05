#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

/*
https://leetcode.com/problems/find-median-from-data-stream

Solution1 simple sort at findMedian
time: o(nlogn). add: o(1). median: sort o(nlogn)
space: o(n) vector

Solution2 insertion sort
time: o(n). add: bin search(logn) insertion(n). median: o(1)
space: o(n)
auto it = lower_bound(v.begin(), v.end(), num);
v.insert(it, num)

Solution3 heaps. min-heap, max-heap
time: o(logn) heap delete/insert logn
priority_queue<int> lo; //max-heap
priority_queue<int, vector<int>, greater<int>> hi; //min-heap
add(num)
 lo.push(num)
 hi.push(num.top())
 lo.pop()
 if (lo.size() < hi.size())
     lo.push(hi.top())
     hi.pop()
 findMin()
     return (lo.size() > hi.size()) ? lo.top() : ((lo.top() + hi.top()) / 2.0)
*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        
        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        if (lo.size() == 0) return 0;
        return (lo.size() > hi.size()) ? lo.top() : (lo.top() + hi.top()) / 2.0;
    }
    
private:
    priority_queue<int> lo; // max-heap
    priority_queue<int, vector<int>, greater<int>> hi; // min-heap
};

class MedianFinder_insertion_sort {
public:
    /** initialize your data structure here. */
    MedianFinder_insertion_sort() {
        
    }
    
    void addNum(int num) {
        if (data_.size() == 0) {
            data_.push_back(num);
        }
        else {
            data_.insert(lower_bound(data_.begin(), data_.end(), num), num);
        }
    }
    
    double findMedian() {
        int n = data_.size();
        if (n == 0) return 0;
        
        return (n % 2 == 1) ? (double)data_[n / 2] : ((data_[n / 2 - 1] + data_[n / 2]) / 2.0);
    }
    
private:
    vector<int> data_;
};

class MedianFinder_simple_sort {
public:
    /** initialize your data structure here. */
    MedianFinder_simple_sort() {
        
    }
    
    void addNum(int num) {
        data_.push_back(num);
    }
    
    double findMedian() {
        int n = data_.size();
        if (n == 0) return 0;
        
        sort(data_.begin(), data_.end());
        return (n % 2 == 1) ? (double)data_[n / 2] : ((data_[n / 2 - 1] + data_[n / 2]) / 2.0);
    }
    
private:
    vector<int> data_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    //Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

    auto obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    assert(obj->findMedian() == 1.5); //-> 1.5
    obj->addNum(3);
    assert(obj->findMedian() == 2); //-> 2

    delete(obj);
    
    return 0;
}