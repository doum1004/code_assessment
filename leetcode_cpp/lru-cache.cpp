#include <iostream>
#include <vector>
#include <cassert>
#include <list>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/lru-cache/

// map for cache, list for used
// time: o(1) // map: get/set o(1), list: erase by iterator and add front/back o(1)
// space: o(capacity)

// cache.put(1, 1);
// cache: 1

// cache.put(2, 2);
// cache: 1 2

// cache.get(1);
// cache: 2 1

// cache.put(3, 3);
// cache: 1 3

// cache.get(2);
// -1

// cache.put(4, 4);
// cache: 3 4

// cache.get(1);
// -1

// used: list<key> (bidirectlist)
// map: map<key, pair<value, used::iterator>>

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        auto it = cache_.find(key);
        if (it == cache_.end()) {
            return -1;
        }
        
        UpdateUsed(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            UpdateUsed(it);
        }
        else {
            if (used_.size() == capacity_) {
                // erase used
                cache_.erase(used_.back());
                used_.pop_back();
            }
            used_.push_front(key);
        }
        
        cache_[key] = {value, used_.begin()};
    }
    
private:
    typedef int KEY;
    typedef int VALUE;
    typedef list<KEY> LK;
    typedef pair<VALUE, LK::iterator> PVI;
    typedef unordered_map<KEY, PVI> M_KPVI;
    
    int capacity_;
    LK used_;
    M_KPVI cache_;

private:
    void UpdateUsed(M_KPVI::iterator it) {
        used_.erase(it->second.second);
        used_.push_front(it->first);
        it->second.second = used_.begin();
    }
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