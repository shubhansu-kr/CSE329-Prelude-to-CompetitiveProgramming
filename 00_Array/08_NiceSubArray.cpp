// https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        vector<int> oddIndex;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] % 2) oddIndex.emplace_back(i);
        }
        
        for (int i = k-1; i < oddIndex.size(); ++i)
        {
            int b = oddIndex[i], a = oddIndex[i-k+1];
            
            int p = a,  q = n-b-1;
            if (i < oddIndex.size()-1) q = oddIndex[i+1] - b - 1; 
            if (i-k >= 0) p = a - oddIndex[i-k] -1;

            ans += ((p*q) + (p+q) + 1);
        }
        
        return ans;
    }
};

class Solution {
    // BruteForce: Sliding window with variable size.
    // Time Limit Exceeded
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            if (flag) break;
            flag = (nums[i] % 2);
        }
        if(!flag) return ans;
        
        
        // Size of subarray is not given, but it must be greater than or equal to k 
        for (int size = k; size <= n; ++size)
        {
            int count = 0;
            for (int i = 0; i < size; ++i)
            {
                if (nums[i] % 2) ++count;
            }
            
            if (count == k) ++ans;

            for (int i = size; i < n; ++i)
            {
                if (nums[i] % 2) ++count;
                if (nums[i-size] % 2) --count;

                if (count == k) ++ans;
            }
            
        }
        
        return ans;
    }
};

int main () {
    
    return 0;
}