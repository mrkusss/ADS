#include <iostream>
#include <vector>
using namespace std;

template<typename T>
int linear_search(const vector<T>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> v = {12,45,23,85,69,128,32,77};
    int target = 32;

    cout << linear_search(v,target);

    return 0;
}