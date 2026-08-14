// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int maxSubarraySum(vector<int>& arr, int k) {

//     int n = arr.size();

//     if(n < k) return 0;

//     int windowSum = 0;

//     // Calculate sum of first window
//     for(int i = 0; i < k; i++) {
//         windowSum += arr[i];
//     }

//     int maxSum = windowSum;

//     // Slide the window
//     for(int i = k; i < n; i++) {

//         windowSum = windowSum + arr[i] - arr[i - k];

//         maxSum = max(maxSum, windowSum);
//     }

//     return maxSum;
// }

// int main() {

//     vector<int> arr = {100, 200, 300, 400};
//     int k = 2; 

//     int result = maxSubarraySum(arr, k);

//     cout << "Maximum Sum Subarray: " << result << endl;

//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MaxSumArray(vector<int>& nums, int result) {

    int n = nums.size();
    int low = 0;
    int high = 1;
    int sum = 0;

    sum = nums[low] + nums[high];
    result = sum;

    while(high < n - 1) {

        low++;
        high++;

        sum = sum - nums[low - 1];
        sum = sum + nums[high];

        result = max(result, sum);
    }

    return result;
}

int main(){

    vector<int> nums = {100, 200, 300, 400};

    int result = 0;

    result = MaxSumArray(nums, result);

    cout << "Maximum Sum Subarray: " << result << endl;

    return 0;
}