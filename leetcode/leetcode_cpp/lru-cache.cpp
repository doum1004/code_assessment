#include <iostream>
#include <vector>
#include <cassert>
#include <list>
#include "../utils.h"

using namespace std;

/*
https://leetcode.com/problems/lru-cache

Solution0. map for cache, list for used
// time: o(1) // map: get/set o(1), list: erase by iterator and add front/back o(1)
// space: o(capacity)
// used: list<key> (bidirectlist)
// map: map<key, pair<value, used::iterator>>

Solution1. Linked list. Relink node on head and tail.
time: get(1) put(1)
space: o(n)
*/

class LRUCache1 {
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

class LRUCache {
    
class MyListNode {
public:
    MyListNode(int _key, int _val) { key = _key; val = _val; }
    int key;
    int val;
    MyListNode* next = nullptr;
    MyListNode* prev = nullptr;
};

public:
    LRUCache(int capacity) {
        n = capacity;
        tail = head;
    }

    int get(int key) {
        if (n == 0 || !hm.count(key)) return -1;

        auto node = hm[key];
        if (node != tail)
        {
            // update least used
            auto prev = node->prev;
            auto next = node->next;
            prev->next = next;
            if (next)
                next->prev = prev;

            node->next = nullptr;
            tail->next = node;
            node->prev = tail;        
            tail = node;
        }
        return node->val;
    }
    
    void put(int key, int value) {
        if (n == 0) return;
        if (hm.count(key)) {
            // update node
            get(key);
            hm[key]->val = value;
            return;
        }

        if (hm.size() == n) {
            // delete Node
            auto tbd = head->next;
            if (tbd == tail)
                tail = head;

            head->next = tbd->next;
            if (tbd->next)
                tbd->next->prev = head;
            hm.erase(tbd->key);
            delete tbd; tbd = nullptr;
        }

        // add node
        hm[key] = new MyListNode(key, value);
        tail->next = hm[key];
        hm[key]->prev = tail;
        tail = hm[key];
    }
    int n = 0;
    unordered_map<int, MyListNode*> hm;
    MyListNode* head = new MyListNode(-1, -1);
    MyListNode* tail = nullptr;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

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