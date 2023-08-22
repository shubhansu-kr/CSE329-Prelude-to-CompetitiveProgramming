// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
public:
    bool checkIfPangram(string sentence) {
        map<char, int> freq;
        for(auto &it: sentence) {
            freq[it]++;
        }
        return freq.size() == 26;
    }
};

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> freq(26, 0);
        for(auto &it: sentence) {
            freq[it-'a']++;
        }
        for(auto &it: freq){
            if (!it) return false;
        }
        return true;
    }
};

int main () {
    
    return 0;
}