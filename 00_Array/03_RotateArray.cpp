// https://leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    // 1, 2, 3, 4, 5, 6, 7
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