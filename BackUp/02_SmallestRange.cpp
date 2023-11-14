// https://leetcode.com/problems/smallest-range-ii/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        float avg = 0; 
        int n = nums.size();
        for(auto &it: nums) avg += it;
        avg /= n;

        int mini = INT_MAX, maxi = INT_MIN;
        for(auto &it: nums){
            int res = it;
            if (abs((it+k) - avg) > abs((it-k)-avg)) {
                res = it-k;
            }
            else if (abs((it+k) - avg) < abs((it-k)-avg)) {
                res = it+k;
            }
            else {
                if (it > avg){
                    res = it-k;
                }
                else{
                    res = it+k;
                }
            }
            maxi = max(maxi, res);
            mini = min(mini, res);
        }

        return (maxi-mini);
    }
};

int main () {
    
    return 0;
}