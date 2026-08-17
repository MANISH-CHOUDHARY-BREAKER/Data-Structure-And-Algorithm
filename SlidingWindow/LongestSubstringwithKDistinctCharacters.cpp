#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longestKSubstr(string &s, int k) {

    int low = 0;
    int high = 0;
    int res = INT8_MIN;
    int n = s.size();

    unordered_map<char, int> f;

    for(high = 0; high < n; high++)
    {
        f[s[high]]++;

        while(f.size() > k)
        {
            f[s[low]]--;
            low++;

            if(f[s[low - 1]] == 0)
            {
                f.erase(s[low - 1]);
            }
        }

        if(f.size() == k)
        {
            int len = high - low + 1;
            res = max(res, len);
        }
    }

    if(res == INT8_MIN)
        return -1;

    return res;
}

int main()
{
    string s = "aabacbebebe";
    int k = 3;

    int result = longestKSubstr(s, k);

    cout << "Longest Substring with K Distinct Characters: "
         << result << endl;

    return 0;
}