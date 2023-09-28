// Find out the gcd of two number: 

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
    // Extended Euclidian Algo: 

    // aX + bY = gcd(a, b)
    // gcd(b, a%b) = gcd(a, b);
    // bX1 + (a%b)Y1 = aX + bY;

    // p % q = p - p/q * q; (Modulus equivalent).
    
    // Solve the eq: 
    // bX1 + (a%b)Y1 = aX + bY;
    // bX1 + (a - a/b * b) Y1 = aX + bY;
    // bX1 + aY1 - (a/b * b)Y1 = aX + bY;
    // aY1 + b(X1 - (a/b)*Y1) = aX + bY;
    
public: 
    int extended_gcd(int a,int b,int *x,int *y)
    {
        if(a==0)
        {
            *x=0;
            *y=1;
            return b;
        }
        
        int x1,y1;
        int gcd=extended_gcd(b%a,a,&x1,&y1);
    
        *x=y1-b/a*x1;
        *y=x1;
        
        return gcd;
    }
};

class Solution {
    // Euclidian Algo
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