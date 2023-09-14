// https://www.geeksforgeeks.org/sum-middle-row-column-matrix/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> v{
                            {2, 5, 7},
                            {3, 7, 2},
                            {5, 6, 9}
                        };

    int n = v.size();

    cout << "The sum of all the element in middle row : " << endl;
    cout << accumulate(v[n / 2].begin(), v[n / 2].end(), 0) << endl;
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(v[i][j], v[j][i]);
    
    cout << "The sum of all the element in middle column : " << endl;
    cout << accumulate(v[n / 2].begin(), v[n / 2].end(), 0);
    
    return 0;
}
