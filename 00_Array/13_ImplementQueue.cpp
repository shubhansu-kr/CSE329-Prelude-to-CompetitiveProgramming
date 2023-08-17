// https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1

#include <bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
};

class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin >> Q;
        while (Q--)
        {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                sq->push(a);
            }
            else if (QueryType == 2)
            {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends

class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};

// Function to push an element x in a queue.
void MyQueue ::push(int x)
{
    // Your Code
    arr[rear] = x;
    rear = (rear+1) % 100005;
    
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop()
{
    // Your Code
    if (rear == front) return -1;
    int x = arr[front];

    front = (front+1)%100005;
    return x;
}

int main()
{

    return 0;
}