// https://leetcode.com/problems/design-circular-queue/description/

#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
    vector<int> q;
    int f, r, n;

public:
    MyCircularQueue(int k)
    {
        vector<int> temp(k, 0);
        q = temp;
        f = -1, r = 0, n = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        if (f == -1)
            f = 0;
        q[r] = value;
        r = (r + 1) % n;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        f = (f + 1) % n;
        if (f == r)
            f = -1, r = 0;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return q[f];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        if (r == 0)
            return q[n - 1];
        return q[r - 1];
    }

    bool isEmpty()
    {
        return f == -1;
        ;
    }

    bool isFull()
    {
        return (r == f);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{

    return 0;
}