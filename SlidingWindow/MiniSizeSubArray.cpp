#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();

    int low = 0;
    int high = 0;
    int result = INT_MAX;
    int sum = 0;

    while(high < n)
    {
        sum = sum + nums[high];

        while(sum >= target)
        {
            int len = high - low + 1;

            result = min(result, len);

            sum = sum - nums[low];
            low++;
        }

        high++;
    }

    if(result == INT_MAX)
    {
        return 0;
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 4, 4 };
    int target = 4;

    int result = minSubArrayLen(target, nums);

    cout << "Minimum Size Subarray Length: " << result << endl;

    return 0;
}