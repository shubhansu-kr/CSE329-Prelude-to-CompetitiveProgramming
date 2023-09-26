// Find out the gcd of two number: 

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public: 
    int gcd(int &a, int &b){
        if (a < b) {
            swap(a, b);
        }
        int rem = a % b;
        if (rem) return gcd(b, rem);
        else return b;
    }
};

int main () {
    Solution obj; 

    int a = 56, b = 28;
    cout << obj.gcd(a, b);
    
    return 0;
}