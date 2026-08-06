#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    int n = nums.size();
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {

        // Skip duplicate first elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;
        int target = -nums[i];

        while (left < right) {

            int sum = nums[left] + nums[right];

            if (sum == target) {

                result.push_back({nums[i], nums[left], nums[right]});

                left++;
                right--;

                // Skip duplicate second elements
                while (left < right && nums[left] == nums[left - 1])
                    left++;

                // Skip duplicate third elements
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}

int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = threeSum(nums);

    cout << "Triplets are:\n";

    for (auto &triplet : ans) {
        cout << "[ ";
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}