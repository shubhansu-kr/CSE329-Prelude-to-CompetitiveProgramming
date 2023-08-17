// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        long long ans = 0;
        long long runningSum = 0;

        unordered_set<int> st;

        bool flag = true;

        for (int i = 0; i < k; ++i)
        {
            if (st.count(nums[i])) {
                flag = false;
            }
            st.insert(nums[i]);
            runningSum += nums[i];
        }

        if (flag) ans = runningSum;

        for (int i = k; i < n; ++i)
        {
            flag = true;
            
            st.erase(nums[i-k]);
            if (st.count(nums[i])) {
                flag = false;
            }
            runningSum += (nums[i] - nums[i-k]);

            if (flag) ans = max(ans, runningSum);
        }
        
        return ans;
    }
}; 

int main () {
    
    return 0;
}