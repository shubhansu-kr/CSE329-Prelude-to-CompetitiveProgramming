// https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
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