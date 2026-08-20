//Longest Repeating Character Replacement 424 leetcode 
// high → expand
//    ↓
// find maximum frequency
//    ↓
// diff = window length - max frequency
//    ↓
// diff > k ?
//    ↓ YES
// low → shrink
//    ↓
// recalculate
//    ↓
// update result
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int find(vector<int>& a)
{
    int maxc= -1;

    for(int i = 0; i < 256; i++)
    {
        maxc = max(maxc, a[i]);
    }
    return maxc;
}

int characterReplacement(string s, int k)
{
    int n = s.size();

    vector<int> f(256, 0);
    int low = 0;
    int high = 0; 
    int res = INT_MIN;

    for (high = 0; high < n; high++)
    {
        f[s[high]]++;

        int len = high - low + 1;
        int maxcnt = find(f);
        int diff = len - maxcnt;

        while(diff > k)
        {
            f[s[low]]--;
            low++;

            maxcnt = find(f);
            len = high - low + 1;
            diff = len - maxcnt;
        }
        len = high -low + 1;

        res = max(res, len);

    }
    return res;
}
int main()
{
    string s = "AABABBA";
    int k = 1;
    int result = characterReplacement(s, k);

    cout<< "Longest Repeating Charater Replacement: " << result << endl;

    return 0 ;
}