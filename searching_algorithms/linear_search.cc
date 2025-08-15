/*
  Linear search checks each element of a list one by one 
until the target is found and works on unsorted or small datasets.
  It is used in simple searches where speed is not critical.
*/
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