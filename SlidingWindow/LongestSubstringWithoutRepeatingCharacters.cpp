//3. Longest Substring Without Repeating Characters
//high → expand
//    ↓
// add character
//    ↓
// duplicate?
//    ↓
// low → shrink
//    ↓
// remove character
//    ↓
// calculate length
//    ↓
// update res
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int lengthOfLongestSubstring(string s){
    
    int n = s.size();

    int low = 0;
    int high = 0;

    int res = INT8_MIN;

    unordered_map<char, int> f;

    for(high = 0; high < n; high++)
    {
        f[s[high]]++;
        int len = high - low + 1;

        while(f.size() < len)
        {
            f[s[low]]--;

            if(f[s[low]] == 0)
            {
                f.erase(s[low]);
            }
            low++;

            len = high - low + 1;
        }
        //now equal 
        len = high - low + 1;
        res = max(res, len);

    }
    if(res == INT8_MIN)
    {
        return 0;
    }
    return res;
}
int main()
{
    string s = "abcabcbb";

    int result = lengthOfLongestSubstring(s);

    cout << "Longest Substring Without Repeating Charaters: " << result << endl;

    return 0;
}