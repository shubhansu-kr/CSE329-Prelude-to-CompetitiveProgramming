// Sort the string 
// https://www.hackerrank.com/challenges/sorting-array-of-strings/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    void sort(vector<string> &str, function<bool(string, string)> comp){
        int n = str.size();
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if (comp(str[i], str[j])){
                    // swap str[j] with str[i] if str[j]'s val is less than str[i]'s val.
                    swap(str[i], str[j]);
                }
            }
        }
    }

};

bool lexicographicSort(string s1, string s2){
    int l1 = s1.length(), l2 = s2.length();
    int len = min(l1, l2);
    for(int i = 0; i < len; ++i){
        if (s2[i] > s1[i]) return false;
        else if (s2[i] == s1[i]) continue;
        else return true;
    }
    return l2 < l1;
}

bool lexicographicSortReverse(string s1, string s2){
    int l1 = s1.length(), l2 = s2.length();
    int len = min(l1, l2);
    for(int i = 0; i < len; ++i){
        if (s2[i] > s1[i]) return true;
        else if (s2[i] == s1[i]) continue;
        else return false;
    }
    return l2 > l1;
}

bool sortByNumberOfDistinctCharacters(string s1, string s2){
    unordered_set<char> f1, f2;
    for(auto &it: s1) f1.insert(it);
    for(auto &it: s2) f2.insert(it);
    return f2.size() < f1.size();
}

bool sortByLength(string s1, string s2){
    return s2.length() < s1.length();
}

int main () {
    Solution obj;

    vector<string> str = {"aaa", "aab", "aaaa", "a"};
    
    obj.sort(str, &lexicographicSort);
    for(auto &it: str){
        cout << it << endl;
    }
    cout << " \n\n";

    obj.sort(str, &lexicographicSortReverse);
    for(auto &it: str){
        cout << it << endl;
    }
    cout << " \n\n";

    obj.sort(str, &sortByNumberOfDistinctCharacters);
    for(auto &it: str){
        cout << it << endl;
    }
    cout << " \n\n";

    obj.sort(str, &sortByLength);
    for(auto &it: str){
        cout << it << endl;
    }
    cout << " \n\n";
    return 0;
}