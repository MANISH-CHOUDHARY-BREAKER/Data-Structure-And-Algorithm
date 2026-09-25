// LeetCode 287: Find the Duplicate Number
// Difficulty: Medium
// Topic: Array | Two Pointers
// Approach: Floyd's Cycle Detection Algorithm

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& a) {

        int slow = 0;
        int fast = 0;

        // Step 1: Detect cycle
        while (true) {

            slow = a[slow];

            fast = a[fast];
            fast = a[fast];

            if (slow == fast) {
                break;
            }
        }

        // Step 2: Find the entrance of the cycle
        slow = 0;

        while (slow != fast) {
            slow = a[slow];
            fast = a[fast];
        }

        return slow;
    }
};

int main() {

    vector<int> a = {1, 3, 4, 2, 2};

    Solution obj;

    int duplicate = obj.findDuplicate(a);

    cout << "Duplicate number: " << duplicate << endl;

    return 0;
}