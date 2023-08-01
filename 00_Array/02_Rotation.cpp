// Rotation in Array

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void rotateClockwise(vector<int> &nums) {
        // Same as using the function
        // rotateClockwiseByKElements(nums, 1);
        // Just pass k = 1;

        int n = nums.size();

        if (n < 2) return;

        int temp = nums[n-1];
        for (int i = n-1; i > 0; --i)
        {
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
    }

    void rotateAntiClockwise(vector<int> &nums) {
        // Same as using the function
        // rotateAntiClockwiseByKElements(nums, 1);
        // Just pass k = 1;

        int n = nums.size();

        if (n < 2) return;

        int temp = nums[0];
        for (int i = 0; i < n-1; ++i)
        {
            nums[i] = nums[i+1];
        }
        nums[n-1] = temp;
    }

    void rotateClockwiseByKElements(vector<int> &nums, int &k) {
        int n = nums.size();

        if (n < 2) return;
        k %= n;

        vector<int> temp(k);
        for (int i = 0; i < k; ++i)
        {
            temp[i] = nums[n-k+i];
        }

        for (int i = n-1; i > k-1; i--)
        {
            nums[i] = nums[i-k];
        }

        for (int i = 0; i < k; ++i)
        {
            nums[i] = temp[i];
        }
    }

    void rotateAntiClockwiseByKElements(vector<int> &nums, int &k) {
        int n = nums.size();

        if (n < 2) return;
        k %= n;

        vector<int> temp(k);
        for (int i = 0; i < k; ++i)
        {
            temp[i] = nums[i];
        }

        for (int i = 0; i < n; ++i)
        {
            nums[i] = nums[i+k];
        }

        for (int i = 0; i < k; ++i)
        {
            nums[n-k+i] = temp[i];
        }
    }

    
};

int main () {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 10;

    Solution *obj = new Solution();
    obj->rotateAntiClockwiseByKElements(nums, k);

    for(auto &it: nums) {
        cout << it << " ";
    }
    return 0;
}