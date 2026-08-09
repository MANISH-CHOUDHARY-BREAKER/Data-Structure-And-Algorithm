#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int TripletsSmall(vector<int>& nums, int target) {

    int n = nums.size();
    sort(nums.begin(), nums.end());

    int ans = 0;

    for(int i = 0; i <n-2; i++){
        int left = i + 1;
        int right = n - 1;

        while (left < right ) {
            int sum = nums[i] + nums[left] + nums[right];

            if(sum >= target) {
                right --;
            } else {
                ans += right - left;
                left++;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {-2, 0, 1, 3};
    int target = 2;
    int result = TripletsSmall(nums, target);

    cout<< "Triplets Small: " << result <<endl;

    return 0;
}