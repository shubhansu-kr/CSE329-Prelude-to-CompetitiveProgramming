// Insertion Operation

#include <bits/stdc++.h>
using namespace std ;

class myArray {
private: 
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
    
    return 0;
}

