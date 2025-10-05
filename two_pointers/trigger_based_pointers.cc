#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestSubarray(vector<int>& values, int k) {
    int left = 0, sum = 0, maxLen = 0;
    for (int right = 0; right < values.size(); right++) {
        sum += values[right];
        while (sum > k) {   //trigger condition
            sum -= values[left];
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main()
{
    int len, k;
    cin >> len >> k;

    vector<int> values(len);

    for (int i = 0; i < len; i++)
    {
        cin >> values[i];
    }

    int maxLen = longestSubarray(values, k);
    
    cout << maxLen;
    return 0;
}