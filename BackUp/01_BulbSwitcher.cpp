// BulbSwitcher: Find the cost of switching all the bulbs

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public:
    int findCost(string bulbSwitch) {
        char sw = '1';
        int cost = 0;
        for(int i = 0; i < bulbSwitch.length(); ++i) {
            if (sw != bulbSwitch[i]) {
                ++cost;
                if (sw == '1') sw = '0';
                else sw = '1';
            }
        }
        return cost;
    }
};

int main () {
    Solution obj;
    cout << obj.findCost("000");
    return 0;
}