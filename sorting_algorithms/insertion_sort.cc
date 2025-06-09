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
vector<T> insertion_sort(vector<T>& arr) {
    for (int i = 0; i< arr.size(); ++i) {
        T key = arr[i];
        int j = i-1;
        while (j>=0 && key<arr[j]) {
            arr[j+1] = arr[j];
            --j;
        }

        arr[j+1] = key;
    }
    return arr;
}

int main() {
    vector<int> v = {3, 5, 1, 9, 2, 7};

    vector<int> sorted = insertion_sort(v);
    printVector(sorted);
    return 0;
}