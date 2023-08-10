// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0, n = arr.size();

        long long sum = 0;
        for (int i = 0; i < k; ++i)
        {
            sum += arr[i];
        }
        
        if (sum/k >= threshold) ++count;

        for (int i = k; i < n; ++i)
        {
            sum += (arr[i]-arr[i-k]);

            if (sum / k >= threshold) ++count;
        }

        return count;
    }
};

int main () {
    
    return 0;
}