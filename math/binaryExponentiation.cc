/*
Binary exponentiation (also called fast exponentiation) is an efficient algorithm for computing powers of a number. 
It works by expressing the exponent in binary form and repeatedly squaring the base, multiplying it into the result 
only when the current bit of the exponent is 1. 
This reduces the time complexity from O(n) to O(log⁡n)
*/

#include <iostream>

using namespace std;

long long fastIncrement(long long num, long long power)
{
    if (power == 0)
    {
        return 1;
    }
    else 
    {
        if (power % 2 == 0)
        {
            long long res = fastIncrement(num, power/2);
            return res * res;
        }
        else 
        {
            return num * fastIncrement(num, power-1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long num, power;

    cin >> num >> power;

    cout << fastIncrement(num, power);

    return 0;
}