#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void printVector(const vector<T>& vec) {
    for (const T& el : vec) {
        cout << el << " ";
    }
    cout << endl;
}


template<typename T>
vector<T> bubble_sort(vector<T>& arr) {
    bool modified = false;

    for (int i = 0; i < arr.size(); ++i) {
        modified = false;
        for (int j = 0; j < arr.size() - 1 - i; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                modified = true;
            }
        }
        if(!modified)
            break;
    }
    return arr;
}

int main() {
    vector<int> v = {3, 5, 1, 9, 2, 7};

    vector<int> sorted = bubble_sort(v);
    printVector(sorted);
    return 0;
}