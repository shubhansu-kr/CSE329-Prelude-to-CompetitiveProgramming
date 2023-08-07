// https://leetcode.com/problems/find-peak-element/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1) return 0;
        if (n == 2) return (nums[0] > nums[1] ? 0 : 1);

        int low = 0, high = n - 1;
        int mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            int prev = mid - 1, next = mid + 1;
            if (prev == -1 )
            {
                return (nums[0] > nums[1] ? 0 : 1);
            }
            if (next == n) {
                return (nums[n-1] > nums[n-2] ? n-1 : n-2);
            }

            if (nums[prev] < nums[mid] && nums[next] < nums[mid])
            {
                return mid;
            }

            nums[prev] < nums[next] ? low = mid + 1 : high = mid - 1;
        }

        return high;
    }
};

int main()
{

    return 0;
}