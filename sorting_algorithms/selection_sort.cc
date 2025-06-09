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
vector<T> selection_sort(vector<T>& arr) {
    for(int i = 0; i<arr.size(); ++i) {
        int min_idx = i;
        for (int j = i + 1; j<arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);

    }
    return arr;
}

int main() {
    vector<int> v = {3, 5, 1, 9, 2, 7};

    vector<int> sorted = selection_sort(v);
    printVector(sorted);
    return 0;
}