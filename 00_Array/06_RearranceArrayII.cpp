// https://leetcode.com/problems/rearrange-array-elements-by-sign/

#include <bits/stdc++.h>
using namespace std ;

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