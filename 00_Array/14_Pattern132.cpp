// https://leetcode.com/problems/132-pattern/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
    }
};

class Solution {

    // [1,0,1,-4,-3]
    // [3,5,0,3,4]

    // Wrong Answer... : We cannot check the next min... because we need to check if next min is also 
    // greater than prevMin.
public:
    bool find132pattern(vector<int>& nums) {
        int prevMin = nums[0], n = nums.size();

        vector<int> nextMin(n, INT_MAX);

        nextMin[n-1] = min(nums[n-1], nextMin[n-1]);
        for (int i = n-2; i >= 0; --i)
        {
            nextMin[i] = min(nums[i], nextMin[i+1]);
        }

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > prevMin && nums[i] > nextMin[i] && prevMin < nextMin[i]){
                return true;
            }

            prevMin = min(prevMin, nums[i]);
        }        

        return false;
    }
};

int main () {
    
    return 0;
}