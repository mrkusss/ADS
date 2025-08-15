/*
        Binary search is an efficient algorithm (O(log n)) for finding a target value in a sorted array
                    by repeatedly dividing the search interval in half.
It is commonly used in search engines, database indexing, and any application requiring fast lookups in sorted data.
*/
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
int binary_search(const vector<T>& arr, int target, int low, int high) {
    if (low <= high) {
        int mid = low + (high-low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return binary_search(arr, target, low, mid - 1);
        else
            return binary_search(arr, target, mid + 1, high);

    }
    return -1;
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int target = 13;
    cout << binary_search(v, target, 0, v.size()-1);
    return 0;
}