// https://leetcode.com/problems/perfect-squares/

#include <bits/stdc++.h>
using namespace std ;

class Solution2 {
    // Tabulation
public:
    int solve(vector<vector<int>> &dp, int n, int i) {
        if (n == 0) return 0;
        if (n < i * i) return 10e5;

        if (dp[n][i] != -1) return dp[n][i];

        int pick = 1 + solve(dp, n-i*i, i);
        int noPick = solve(dp, n, i+1);
        
        return dp[n][i] = min(pick, noPick);
    }

    int numSquares(int n) {
        vector<vector<int>> dp(n+1, vector<int>((sqrt(n)+1), 10e5));

        
        return dp[n][1];
    }
};

class Solution1 {
    // Recursion: Memoization
public:
    int solve(vector<vector<int>> &dp, int n, int i) {
        if (n == 0) return 0;
        if (n < i * i) return 10e5;

        if (dp[n][i] != -1) return dp[n][i];

        int pick = 1 + solve(dp, n-i*i, i);
        int noPick = solve(dp, n, i+1);
        
        return dp[n][i] = min(pick, noPick);
    }

    int numSquares(int n) {
        vector<vector<int>> dp(n+1, vector<int>((sqrt(n)+1), -1));
        return solve(dp, n, 1);
    }
};

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