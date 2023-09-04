// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

#include <bits/stdc++.h>
using namespace std ;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:

    Node* solve(Node *parent) {
        Node *p = parent;
        while(p) {
            if (p->child) {
                Node *temp = solve(p);
            }
            p = p->next;
        }
        return parent;
    }

    Node* flatten(Node* head) {
        if (!head) return head;
        solve(head);
        return head;
    }
};

int main () {
    
    return 0;
}