// https://leetcode.com/problems/perfect-squares/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // BruteForce: Recursion
public:
    int solve(int n, int i) {
        if (n == 0) return 0;
        if (n < i * i) return 10e5;

        int pick = 1 + solve(n-i*i, i);
        int noPick = solve(n, i+1);
        
        return min(pick, noPick);
    }
    int numSquares(int n) {
        return solve(n, 1);
    }
};

int main () {
    
    Solution obj;
    cout << obj.numSquares(12);

    return 0;
}