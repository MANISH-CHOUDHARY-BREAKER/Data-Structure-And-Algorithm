#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarraySum(vector<int>& arr, int k) {

    int n = arr.size();

    if(n < k) return 0;

    int windowSum = 0;

    // Calculate sum of first window
    for(int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Slide the window
    for(int i = k; i < n; i++) {

        windowSum = windowSum + arr[i] - arr[i - k];

        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {

    vector<int> arr = {100, 200, 300, 400};
    int k = 2; 

    int result = maxSubarraySum(arr, k);

    cout << "Maximum Sum Subarray: " << result << endl;

    return 0;
}