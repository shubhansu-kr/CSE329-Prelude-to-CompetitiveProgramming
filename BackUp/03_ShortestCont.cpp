// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        if (nums[0] > nums[n-1]) return n;

        int i = 1, j = n-2;

        int left = 0, right = n-1;
        for(i = 1; i < n; ++i){
            if (nums[i] < nums[i-1]) {
                left = i-1;
                break;
            }
        } 

        for(j = n-1; j > 0; --j) {
            if (nums[j] < nums[j-1]) {
                right = j;
                break;
            }
        }



        // while(i <= j) {
        //     if (nums[i] < nums[i-1] && l) {
        //         left = i-1;
        //         l = false;
        //     }else {
        //         ++i;
        //     } 

        //     if (nums[j] > nums[j+1]) {
        //         right = j+1;
        //         r = false;
        //     }else {
        //         --j;
        //     }
        // }


    }
};

int main () {
    
    return 0;
}