// https://leetcode.com/problems/rearrange-array-elements-by-sign/

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
public:
    // Inplace arrangement: TLE
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n-1; ++i)
        {
            if(i % 2) {
                // odd index: negative
                if (nums[i] < 0) continue;

                // get next positive index.
                int index = i+1;
                while(index < n && nums[index] > 0) {
                    ++index;
                }

                // shift the positive element.
                while(index > 0 && index > i) {
                    swap(nums[index], nums[index-1]);
                    --index;
                }
            }
            else {
                // even index: positive
                if (nums[i] > 0) continue;
                
                // get next negative index.
                int index = i+1;
                while(index < n && nums[index] < 0) {
                    ++index;
                }

                // shift the negative element.
                while(index > 0 && index > i) {
                    swap(nums[index], nums[index-1]);
                    --index;
                }
            }
        }
        
        return nums;
    }
};

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int *p = &nums[0];
        int *n = &nums[0];  
        vector<int> res;
        int toggle = 1;
        while (res.size() != nums.size())
        {
            if (toggle)
            {
                while (*p < 0)
                    p++;
                res.push_back(*p);
                p++;
                toggle = 0;
            }
            else
            {
                while (*n > 0)
                    n++;
                res.push_back(*n);
                n++;
                toggle = 1;
            }
        }
        return res;
    }
};

int main () {
    
    return 0;
}