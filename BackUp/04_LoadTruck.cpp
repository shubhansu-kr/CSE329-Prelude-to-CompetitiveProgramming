// https://leetcode.com/problems/maximum-units-on-a-truck/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();

        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &v1, vector<int> &v2){
            return v1[1] > v2[1];
        });

        int ans = 0, total = truckSize;
        for(auto &it: boxTypes){
            if (!total) break;

            int units = min(it[0], total);
            ans += units * it[1];
            total -= units;
        }

        return ans;
    }
};

int main () {
    
    return 0;
}