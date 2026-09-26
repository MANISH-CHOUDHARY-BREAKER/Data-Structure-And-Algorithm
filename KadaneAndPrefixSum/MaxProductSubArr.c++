// For LeetCode 152 — Maximum Product Subarray, your previous Kadane logic needs one important change because negative numbers can turn the smallest product into the largest product.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 152: Maximum Product Subarray
    Difficulty: Medium
    Topic: Array | Dynamic Programming

    My Logic:
    - miniEnd = minimum product ending at current index
    - maxEnd = maximum product ending at current index
    - v1 = current element
    - v2 = miniEnd * current element
    - v3 = maxEnd * current element
*/

class Solution {
public:
    int maxProduct(vector<int>& a) {
        int miniEnd = a[0];
        int maxEnd = a[0];
        int maxProduct = a[0];

        for (int i = 1; i < a.size(); i++) {
            int v1 = a[i];
            int v2 = miniEnd * a[i];
            int v3 = maxEnd * a[i];

            maxEnd = max(v1, max(v2, v3));
            miniEnd = min(v1, min(v2, v3));

            maxProduct = max(maxProduct, maxEnd);
        }

        return maxProduct;
    }
};

int main() {
    vector<int> a = {2, 3, -2, 4};

    Solution obj;

    cout << "Maximum Product: "
         << obj.maxProduct(a) << endl;

    return 0;
}