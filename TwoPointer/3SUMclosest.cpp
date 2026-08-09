#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int threeSumClosest(vector<int>& nums, int target){

    int n =nums.size();
    sort(nums.begin(), nums.end());
    int result = nums[0] + nums[1] + nums[2];

    for(int i = 0; i<n-2; i++) {  
        int left = i +1;
        int right = n - 1;

        while(left < right) {
            int s = nums[i] + nums[left] + nums[right];

            //check if current sum is closer to target 
            if(abs(s - target) < abs(result - target)) {
                result = s;
            }

            if(s < target) {
                left++;
            }else if(s > target) {
                right --;
            }else {
                return s;
            }
        }
    }
    return result;
}
int main (){
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int result = threeSumClosest(nums, target);

    cout << "Closest Sum: " << result <<endl;

    return 0;
}