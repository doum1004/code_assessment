#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/maximum-frequency-stack/

//Soltuion1. Two HashMaps (valueCounter, freqList) and maxFreq.
//time: o(1) for push, pop
//space: o(n). HashMaps(2n)

1) push (5)
valueCounter: map for value w counter
5: 1

freqList: map for freq w value
1: 5

maxFreq = 1

2) push (7)
valueCounter: map for value w counter
5: 1
7: 1

freqList: map for freq w value
1: 5, 7

maxFreq = 1

3) push (5)
valueCounter: map for value w counter
5: 2
7: 1

freqList: map for freq w value
1: 5, 7
2: 5

maxFreq = 2

4) push (7)
valueCounter: map for value w counter
5: 2
7: 2

freqList: map for freq w value
1: 5, 7
2: 5, 7

maxFreq = 2

5) push (4)
valueCounter: map for value w counter
5: 2
7: 2
4: 1

freqList: map for freq w value
1: 5, 7, 4
2: 5, 7

maxFreq = 2

6) push (5)
valueCounter: map for value w counter
5: 3
7: 2
4: 1

freqList: map for freq w value
1: 5, 7, 4
2: 5, 7
3: 5

maxFreq = 3

7) pop
if not freqList.counter(maxFreq): return

res = freqList[maxFreq].pop()
valueCounter[res]--

while maxFreq not in freqList[maxFreq]: maxFreq--

return res


*/
class FreqStack {
public:
    FreqStack() {
        maxFreq_ = 0;
    }
    
    void push(int x) {
        valueCounter_[x]++;
        auto freq = valueCounter_[x];
        if (freq > maxFreq_)
            maxFreq_ = freq;
        freqList_[freq].push_back(x);
    }
    
    int pop() {
        if (maxFreq_ == 0) throw length_error("");
        
        auto x = freqList_[maxFreq_].back();
        freqList_[maxFreq_].pop_back();
        valueCounter_[x]--;
        if (freqList_[maxFreq_].size() == 0)
            maxFreq_--;
        return x;
    }
    
    unordered_map<int,int> valueCounter_;
    unordered_map<int,vector<int>> freqList_;
    int maxFreq_;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

int main()
{
    auto obj = new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);
    assert(obj->pop() == 5);
    assert(obj->pop() == 7);
    assert(obj->pop() == 5);
    assert(obj->pop() == 4);
    assert(obj->pop() == 7);

    return 0;
}