// 

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    // Use an extra array.
    // TC: O(n)
    // SC: O(n)
    void rearrange(vector<int> &nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        for(auto &it: nums) {
            if(it < n) {
                ans[it] = it;
            }
        }
    }
};

int main () {
    
    return 0;
}