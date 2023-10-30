// KMP string matching algorithm
// https://practice.geeksforgeeks.org/problems/last-match1928/1

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:

    vector<int> findLCS(string &s){
        int n = s.length();
        vector<int> lcs(n, 0);

        for(int i = 1; i < n; ++i) {
            int j = 0;
            for(j = 0; j <= i/2; ++j) {
                if (s[j] == s[i-j]) continue;
                else {
                    break;
                }
            }
            lcs[i] = j;
        }

        return lcs;
    }

    int findLastOccurence(string A,string B){
        //Code Here
        int n = A.length(), m = B.length();
        vector<int> lcs = findLCS(B);
        int ans = -1;
        int i = 0, j = 0;

        while (i <= n) {
            if (j == m) {
                ans = i-j;
                if (j != 0) j = lcs[j-1];
            }

            if (i == n) break;

            if (A[i] == B[j]) {
                ++i, ++j;
            }
            else {
                if (j != 0) j = lcs[j-1];
                else ++i;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends