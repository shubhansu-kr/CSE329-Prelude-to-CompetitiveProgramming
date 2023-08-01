// Deletion in Array

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

    void deleteElementAtEnd() {
        deleteElementAtIndex(index-1);
    }

    void deleteElementAtBeginning() {
        deleteElementAtIndex(0);
    }

    void deleteElementAtIndex(int n){
        if (index == 0) {
            cout << "Array Empty\n";
            return;
        }
        for (int i = n; i < index; ++i)
        {
            arr[i] = arr[i+1];
        }
        --index;
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