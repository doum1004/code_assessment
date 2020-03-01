#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include "../utils.h"

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

bool isEqual(Node* l, Node* r) {
    if (l != nullptr && r != nullptr) {
        if (l->random != nullptr || r->random != nullptr) {
            if (l->random == nullptr || r->random == nullptr) return false;
            if (l->random->val != r->random->val) return false;
        }
        return (l->val == r->val && isEqual(l->next, r->next));
    }

    return (l == nullptr && r == nullptr) ? true : false;
}

/**
copy linked list
time: o(n) : n+n
space: o(1) : because use only exist and answer

[7, null] [13, 0]

// 1. store exist with new in map
map<node*, node*>
[7] = [7`]
[0] = [0']

// 2. and find new random from map
13, 0
13', 0'

prehead = new Node(-1);
prehead->next = head;

new_prehead = new Node(-1);
newhead = new_prehead

iterate list from head
    new_prehead->next = new Node(head->val)
    new_prehead = new_prehead->next
    map[head] = new_prehead

head = prehead->next
newhead = new_prehead->next
iterate list from head and store reandom
    random = head->random
    if (random && map->find(head->random) != end)
        newhead->random = map[head->random]
    head = head->next
    newhead = newhead->next
**/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        
        auto prehead = new Node(-1);
        prehead->next = head;

        auto new_prehead = new Node(-1);
        auto newhead = new_prehead;

        auto map = unordered_map<Node*, Node*>();
        while (head != nullptr) {
            // add copied list with data
            newhead->next = new Node(head->val);
            newhead = newhead->next;
            map[head] = newhead; // store in map with exist and new
            
            head = head->next; // move to next
        }
        
        head = prehead->next;
        newhead = new_prehead->next;
        
        while (head != nullptr) {
            auto random = head->random;
            if (random != nullptr && map.find(head->random) != map.end())
                newhead->random = map[head->random];
            head = head->next;
            newhead = newhead->next;
        }
        
        return new_prehead->next;
    }
};

int main()
{
    auto input1_1 = new Node(7);
    auto input1_2 = new Node(13);
    auto input1_3 = new Node(11);   
    auto input1_4 = new Node(10);   
    auto input1_5 = new Node(1);
    input1_1->next = input1_2;
    input1_2->next = input1_3;
    input1_2->random = input1_1;
    input1_3->next = input1_4;
    input1_3->random = input1_5;
    input1_4->next = input1_5;
    input1_4->random = input1_3;
    input1_5->random = input1_1;

    assert(isEqual(Solution().copyRandomList(input1_1), input1_1));
    return 0;
}