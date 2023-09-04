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

class Solution1 {
    // Iterative Solution
public:
    Node* solve(Node *parent) {
        Node *p = parent, *prev = nullptr;
        while(p) {
            if (p->child) {
                Node *tail = solve(p->child);
                Node *temp = p->next;

                p->next = p->child;
                p->child->prev = p;
                p->child = nullptr;

                tail->next = temp;
                if (temp) temp->prev = tail;

                p = tail ;
            }
            prev = p;
            p = p->next;
        }
        return prev;
    }

    Node* flatten(Node* head) {
        Node *p = head, *temp;
        while(p) {
            if (p->child){
                temp = p->next;

                Node * q = p->child;

                p->next = q;
                q->prev = p;

                while(q->next) {
                    q = q->next;
                }

                q->next = temp;
                if (temp) temp->prev = q;
            }
            p = p->next;
        }
        return head;
    }
};

class Solution {
    // Recursive Solution
public:
    Node* solve(Node *parent) {
        Node *p = parent, *prev = nullptr;
        while(p) {
            if (p->child) {
                Node *tail = solve(p->child);
                Node *temp = p->next;

                p->next = p->child;
                p->child->prev = p;
                p->child = nullptr;

                tail->next = temp;
                if (temp) temp->prev = tail;

                p = tail ;
            }
            prev = p;
            p = p->next;
        }
        return prev;
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