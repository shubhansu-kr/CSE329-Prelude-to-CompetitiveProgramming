// https://leetcode.com/problems/simplify-path/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        
        st.push("/");
        string dir = "";

        for (int i = 1; i < path.length(); ++i)
        {
            if (path[i] == '/') {
                if (dir.length() == 0) {
                    
                }
            }
            else if (path[i] == '.') {

            }
            else {
                dir.push_back(path[i]);
            }
        }
        
    }
};

int main () {
    
    return 0;
}