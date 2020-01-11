#include <iostream>
#include <vector>
#include <cassert>
#include <list>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/lru-cache/
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {
        
    }
    
    int get(int key) {
        if (key < 1) return -1;

        auto it = cache_.find(key);
        if (it == cache_.end()) return -1;
        updateUsed(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        if (key < 1) return;
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            updateUsed(it);
        }
        else {
            if (used_.size() == capacity_) {
                cache_.erase(used_.back());
                used_.pop_back();
            }
            used_.push_front(key);
        }
        cache_[key] = {value, used_.begin()};
    }

private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> MIPII;

    void updateUsed(MIPII::iterator it) {
        auto key = it->first;
        used_.erase(it->second.second);
        used_.push_front(key);
        it->second.second = used_.begin();
    }

    int capacity_;
    LI used_;
    MIPII cache_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    auto cache = new LRUCache( 2 /* capacity */ );

    cache->put(1, 1);
    cache->put(2, 2);
    assert(cache->get(1) == 1);       // returns 1
    cache->put(3, 3);    // evicts key 2
    assert(cache->get(2) == -1);       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    assert(cache->get(1) == -1);       // returns -1 (not found)
    assert(cache->get(3) == 3);       // returns 3
    assert(cache->get(4) == 4);      // returns 4

    delete(cache);
    
    return 0;
}