/*
The two pointers or parallel pointers technique is a common algorithmic approach 
where two indices (pointers) move through an array (or string) at the same time, 
        usually in the same direction or toward each other, 
        to efficiently find relationships between elements.

Typical uses:

Finding pairs with a specific sum or difference

Merging sorted arrays

Removing duplicates

Sliding window problems
*/
//Find all pairs (a, b) such that b - a = k
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int len, num;
    cin >> len >> num;

    vector<int> values(len);

    for (int i = 0; i < len; i++)
    {
        cin >> values[i];
    }

    sort(values.begin(), values.end());

    vector<pair<int,int>> res;
    int left = 0, right = 1;
    
    while (right < len)
    {
        int val = values[right] - values[left];

        if (val == num) 
        {
            res.push_back({values[right], values[left]}); 
            right++; 
            left++;
        }
        else if (val < num) right++;
        else left++;

        if (left == right) right++;
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << "(" << res[i].first << ", " << res[i].second << ")\n"; 
    }

    return 0;
}