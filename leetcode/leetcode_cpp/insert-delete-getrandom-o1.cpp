#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

/**
https://leetcode.com/problems/insert-delete-getrandom-o1

Solution1. Use map, vector.
// time: insert(1) remove(1) rand(1)
// space: o(n) 2n

vector store values.
Map store values and index.

insert: add in vector. add in map with vector index.
remove: before remove, swap last val and target val. and update index in map.
rand: get rand num from size

*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map_.count(val))
            return false;
        map_[val] = list_.size();
        list_.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!map_.count(val))
            return false;
        auto idx = map_[val]; // get value index
        auto last_val = list_.back(); // get last val
        list_[idx] = last_val; // set last val in index
        map_[last_val] = idx; // update idx on last val
        map_.erase(val); // remove item in map
        list_.pop_back(); // remove last in list
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return list_[rand() % list_.size()];
    }

private:
    unordered_map<int, int> map_;
    vector<int> list_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    auto randomSet = new RandomizedSet();
    randomSet->insert(1);
    randomSet->remove(2);
    randomSet->insert(2);
    auto expected1 = vector<int> {1,2};
    assert(find(expected1.begin(), expected1.end(), randomSet->getRandom()) != expected1.end());
    randomSet->remove(1);
    randomSet->insert(2);
    randomSet->insert(3);
    auto expected2 = vector<int> {2,3};
    assert(find(expected2.begin(), expected2.end(), randomSet->getRandom()) != expected2.end());

    delete randomSet;
    return 0;
}