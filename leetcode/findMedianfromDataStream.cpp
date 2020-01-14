#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        
        hi.push(lo.top());
        lo.pop();

        if (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return (lo.size() > hi.size()) ? (double) lo.top() : (lo.top() + hi.top()) / 2.0;
    }

private:
    priority_queue<int> lo; //max-heap
    priority_queue<int, vector<int>, greater<int>> hi;
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