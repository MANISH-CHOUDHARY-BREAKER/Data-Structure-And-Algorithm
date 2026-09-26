
// LeetCode 202: Happy Number
// Difficulty: Easy
// Topic: Math | Two Pointers
// Approach: Floyd's Cycle Detection Algorithm
// Slow & Fast Pointer Technique

#include <iostream>
using namespace std;

class Solution
{
public:

    // Calculate sum of squares of digits
    int fun(int n)
    {
        int sum = 0;

        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;

        while (fast != 1)
        {
            // Slow moves one step
            slow = fun(slow);

            // Fast moves two steps
            fast = fun(fast);
            fast = fun(fast);

            // Cycle detected
            if (slow == fast && slow != 1)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    int n = 19;

    Solution obj;

    if (obj.isHappy(n))
    {
        cout << n << " is a Happy Number" << endl;
    }
    else
    {
        cout << n << " is not a Happy Number" << endl;
    }

    return 0;
}