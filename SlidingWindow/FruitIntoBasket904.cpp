#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int totalFruit(vector<int>& a) {
    unordered_map<int, int> f;

    int low=0;
    int high=0;
    int n = a.size();
    int res = INT8_MIN;

    for(high = 0; high < n; high++) 
    {
        f[a[high]]++;

        while(f.size() > 2)
        {
            f[a[low]]--;

            if(f[a[low]]==0)
            f.erase(a[low]);

            low++;
        }
        int len = high-low+1;
        res = max(res, len);
    }
    return res;
}
int main()
{
    vector<int> a = {1, 2, 3, 2, 2};

    int result = totalFruit(a);

    cout<< "Maximum Fruits: " << result <<endl;

    return 0;
}