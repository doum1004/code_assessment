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

/*

Solution1. Using Map. (Save copied pointer in map)
time: o(n) n + n
space: o(n) store hash map

1. Create dummy
2. Iterate head and create copy and save it into map for random pointer

Solution2. Without map. origin node points new copied
time: o(n)
space: o(1)

1. Iterate origin and copy for the new. And Make origin node->next points copy and copy points node->next
- node1 -> node1-copy -> node2 -> node2-copy
2. Iterate to set random
- node1-copy->random-> ...
3. separate cloned
- node1 -> node2
- node1 copy -> node2 copy

*/

class Solution {
public:
    Node* copyRandomList_1(Node* head) {
        Node* dummy = new Node(-1);        

        auto n1 = head;
        auto n2 = dummy;

        unordered_map<Node*, Node*> m;
        while (n1) {
            n2->next = new Node(n1->val);
            m[n1] = n2->next;
            n1 = n1->next;
            n2 = n2->next;
        }

        n1 = head;
        n2 = dummy->next;
        while (n1) {
            n2->random = m[n1->random];

            n1 = n1->next;
            n2 = n2->next;
        }
        return dummy->next;
    }

    Node* copyRandomList_2(Node* head) {
        if (!head) return nullptr;
        //
        Node* origin = head;
        while (origin) {
            auto cloned = new Node(origin->val);
            cloned->next = origin->next;
            origin->next = cloned;
            origin = cloned->next;
        }

        //
        origin = head;
        while (origin) {
            if (origin->random) {
                origin->next->random = origin->random->next;
            }
            else {
                origin->next->random = nullptr;
            }
            origin = origin->next->next;
        }
        
        //
        origin = head;
        auto res = origin->next;
        while (origin) {
            auto temp = origin->next;
            origin->next = temp->next;
            origin = origin->next;

            if (origin)
                temp->next = origin->next;
            else
                temp->next = nullptr;
        }
        return res;
    }

    Node* copyRandomList(Node* head) {
        return copyRandomList_2(head);
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
