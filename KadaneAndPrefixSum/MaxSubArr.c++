#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 53: Maximum Subarray
    Approach: Kadane's Algorithm

    My Logic:
    1. bestEnd stores the maximum subarray sum ending at current index.
    2. v1 = continue the previous subarray.
    3. v2 = start a new subarray from current element.
    4. bestEnd = max(v1, v2)
    5. maxSum stores the maximum sum found so far.
*/

class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int bestEnd = a[0];
        int maxSum = a[0];

        for (int i = 1; i < a.size(); i++) {
            int v1 = bestEnd + a[i];
            int v2 = a[i];

            bestEnd = max(v1, v2);
            maxSum = max(maxSum, bestEnd);
        }

        return maxSum;
    }
};

int main() {
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution obj;

    cout << "Maximum Subarray Sum: "
         << obj.maxSubArray(a) << endl;

    return 0;
}