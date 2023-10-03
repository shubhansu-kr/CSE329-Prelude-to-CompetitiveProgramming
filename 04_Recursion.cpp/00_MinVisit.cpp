// https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // TLE: 1050/1069
    // Optimise Code
public:
    int solve(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j){
        if (i >= grid.size()-1 && j >= grid[0].size()-1) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int k = grid[i][j];

        int steps = 1e6;

        // Move righwards. 
        for(int col = j+1; col <= k+j; ++col) {

            // Check Valid 
            if (col >= grid[0].size()) continue;
            steps = min(steps, 1 + solve(grid, dp, i, col));
        }

        // Move downwards. 
        for(int row = i+1; row <= k+i; ++row) {

            // Check Valid 
            if (row >= grid.size()) continue;
            steps = min(steps, 1 + solve(grid, dp, row, j));
        }

        return dp[i][j] = steps;
    }

    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        int ans = solve(grid, dp, 0, 0);

        return ans == 1e6 ? -1 : ans+1; 
    }
};

int main () {
    
    return 0;
}