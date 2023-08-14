// https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>
using namespace std ;

class Solution2 {
    // Summary: 
public: 
    void rotateClockwisePrimeDiagonal(vector<vector<int>>& matrix) {
        // Inputs: 
        int n = matrix.size();
        
        // Solution: 
        reverse(matrix.begin(), matrix.end());

        // swap along the primary diagonal.
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }            
        }

        // Reverse then swap
    }

    void rotateClockwiseSecondryDiagonal(vector<vector<int>>& matrix) {
        // Inputs: 
        int n = matrix.size();
        
        // Solution: 

        // swap the along the secondry diagonal 
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n-1-i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }            
        }

        reverse(matrix.begin(), matrix.end());

        // Swap Then Reverse.
    }
    
    void rotateAntiClockwisePrimeDiagonal(vector<vector<int>>& matrix) {
        // Inputs: 
        int n = matrix.size();
        
        // Solution: 

        // swap along the primary diagonal.
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }            
        }

        reverse(matrix.begin(), matrix.end());
        
        // Swap then reverse.
    }

    void rotateAntiClockwiseSecondryDiagonal(vector<vector<int>>& matrix) {
        // Inputs: 
        int n = matrix.size();
        
        // Solution: 
        reverse(matrix.begin(), matrix.end());

        // swap the along the secondry diagonal 
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n-1-i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }            
        }

        // Reverse then swap
    }
};

class Solution1 {
    // To rotate the matrix clockwise

    // Reverse the array -> swap the symmetry along diagonal
    // diagonal(0,0 to n-1,n-1);

    // or we can change the diagonal and we have to change the order of steps.
    // swap the symmetry along diagonal(0, n-1 to n-1, 0) -> reverse the array, 
    // will result in clockwise rotation.

    // To rotate the matrix anticlockwise
    // Swap the symmetry along diagonal(primary) -> reverse the array.

    // or we can change the diagonal and we have to change the order of steps.
    // reverse the array -> swap the symmetry along diagonal(0, n-1 to n-1, 0)  
    // will result in anti-clockwise rotation.

public:
    void rotate(vector<vector<int>>& matrix) {
        // Inputs: 
        int n = matrix.size();
        
        // Solution: 
        reverse(matrix.begin(), matrix.end());

        // swap the symmetry 
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }            
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
    }
};

int main () {
    
    return 0;
}