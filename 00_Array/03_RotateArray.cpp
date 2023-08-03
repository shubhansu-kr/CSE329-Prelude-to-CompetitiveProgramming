// https://leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>
using namespace std ;

class Solution4 {
public:
    // Rotate Anti Clockwise | Rotate left (Approach2)

    // Time complexity: O(N)
    // Space Complexity: O(1)

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;

        // Divide the array into two parts 
        // 0 to K-1 | K To N-1 
        // Reverse both the parts 
        // Reverse the whole array

        for (int i = 0; i < k/2; ++i)
        {
            swap(nums[i], nums[k-i-1]);
        }

        for (int i = 0; i < (n-k)/2; i++)
        {
            swap(nums[k+i], nums[n-1-i]);
        }
            
        for (int i = 0; i < n/2; ++i)
        {
            swap(nums[i], nums[n-i-1]);
        }

        // 1, 2, 3, 4, 5, 6, 7  -> 4, 5, 6, 7, 1, 2, 3
        // n = 7  |  k = 3

        // 1, 2, 3 | 4, 5, 6, 7                  Divide
        // 3, 2, 1 | 7, 6, 5, 4                  Reverse Both part
        // 4, 5, 6, 7, 1, 2, 3                   Reverse the whole array
    }
};

class Solution3 {
public:
    // Rotate Anti Clockwise | Rotate left (Approach1)

    // Time complexity: O(N)
    // Space Complexity: O(1)

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;

        // Reverse the whole array
        // Divide the array into two parts 
        // 0 to N-K-1 | N-K To N-1 
        // Reverse both the parts 


        for (int i = 0; i < n/2; ++i)
        {
            swap(nums[i], nums[n-i-1]);
        }

        for (int i = 0; i < (n-k)/2; ++i)
        {
            swap(nums[i], nums[n-k-i-1]);
        }

        for (int i = 0; i < k/2; i++)
        {
            swap(nums[n+k+i], nums[n-1-i]);
        }
            
        // 1, 2, 3, 4, 5, 6, 7  -> 4, 5, 6, 7, 1, 2, 3
        // n = 7  |  k = 3

        // 7, 6, 5, 4, 3, 2, 1                   Reverse the whole array
        // 7, 6, 5, 4 | 3, 2, 1                  Divide
        // 4, 5, 6, 7 | 1, 2, 3                 Reverse both part    

    }
};

class Solution2 {
public:
    // Rotate Clockwise | Rotate Right (Approach2)

    // Time complexity: O(N)
    // Space Complexity: O(1)

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;

        // Reverse the whole array
        // Divide the array into two parts 
        // 0 to k | k To N-1 
        // Reverse both the parts 


        for (int i = 0; i < n/2; ++i)
        {
            swap(nums[i], nums[n-i-1]);
        }

        for (int i = 0; i < k/2; i++)
        {
            swap(nums[i], nums[k-1-i]);
        }
        
        for (int i = 0; i < (n-k)/2; ++i)
        {
            swap(nums[k+i], nums[n-i-1]);
        }

            
        // 1, 2, 3, 4, 5, 6, 7  -> 5, 6, 7, 1, 2, 3, 4 
        // n = 7  |  k = 3

        // 7, 6, 5, 4, 3, 2, 1                   Reverse the whole array
        // 7, 6, 5 | 4, 3, 2, 1                  Divide
        // 5, 6, 7 | 1, 2, 3, 4                  Reverse both part    

    }
};

class Solution1 {
public:
    // Rotate Clockwise | Rotate Right (Approach1)

    // Time complexity: O(N)
    // Space Complexity: O(1)

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;

        // Divide the array into two parts 
        // 0 to N-k | N-K+1 To N-1 
        // Reverse both the parts 
        // Reverse the whole array

        for (int i = 0; i < (n-k)/2; i++)
        {
            swap(nums[i], nums[n-k-1-i]);
        }
        
        for (int i = 0; i < k/2; ++i)
        {
            swap(nums[n-k+i], nums[n-i-1]);
        }

        for (int i = 0; i < n/2; ++i)
        {
            swap(nums[i], nums[n-i-1]);
        }
               

        // 1, 2, 3, 4, 5, 6, 7  -> 5, 6, 7, 1, 2, 3, 4 
        // n = 7  |  k = 3

        // 1, 2, 3, 4 | 5, 6, 7                  Divide
        // 4, 3, 2, 1 | 7, 6, 5                  Reverse both part    
        // 5, 6, 7, 1, 2, 3, 4                   Reverse whole array

    }
};

class Solution {
public:
    // 1, 2, 3, 4, 5, 6, 7
    // Time Complexity: O(N)
    // Space Complexity: O(K%N)

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;

        vector<int> temp(k);
        for (int i = n-k; i < n; ++i)
        {
            temp[i-n+k] = nums[i];  
        }

        for (int i = n-1; i >= k; --i)
        {
            nums[i] = nums[i-k];
        }
        
        for (int i = 0; i < k; ++i)
        {
            nums[i] = temp[i];
        }
    }
};

int main () {
    
    return 0;
}