// Insertion Operation

#include <bits/stdc++.h>
using namespace std ;

class myArray {
public:
    int index;
    int maxSize;

    int *arr;

    myArray(){
        index = 0;
        maxSize = 0;
    }

    myArray(int size){
        index = 0;
        maxSize = size;
        arr = new int(size);
    }

    void insertElementAtEnd(int x) {
        insertElementAtIndex(x, index);
    }

    void insertElementAtBeginning(int x) {
        insertElementAtIndex(x, 0);
    }

    void insertElementAtIndex(int x, int n){
        if (index == maxSize) {
            cout << "Array Full\n";
            return;
        }
        for (int i = index; i > n; --i)
        {
            arr[i] = arr[i-1];
        }
        arr[n] = x;
        ++index;
    }

    void printArray() {
        for (int i = 0; i < index; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main () {
    
    myArray arr(10);
    arr.insertElementAtBeginning(1);
    arr.insertElementAtBeginning(2);
    arr.insertElementAtBeginning(3);
    arr.insertElementAtEnd(0);

    arr.insertElementAtIndex(4, 3);

    arr.printArray();

    return 0;
}

