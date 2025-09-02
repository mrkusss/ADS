/*
    Quick sort is a divide-and-conquer algorithm that selects a pivot, 
    partitions the array around it, and recursively sorts the partitions.
It is widely used in high-performance sorting tasks due to its average-case efficiency.
*/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

template<typename T>
void printVector(const vector<T>& vec) {
    for (const T& el : vec) {
        cout << el << " ";
    }
    cout << endl;
}

template<typename T>
int partition(vector<T>& arr, int low_idx, int high_idx) {
    T pivot = arr[high_idx];

    int i = low_idx;
    int j = high_idx - 1;

    while (true) {
        while (i < high_idx && arr[i] < pivot) {
            ++i;
        }

        while (j >= low_idx && arr[j] > pivot) {
            --j;
        }

        if (i >= j) {
            break;
        }

        swap(arr[i], arr[j]);
    }

    swap(arr[i], arr[high_idx]);

    return i;
}

template<typename T>
void quick_sort(vector<T>& arr, int low_idx, int high_idx) {
    if (low_idx > high_idx) {
        return;
    }

    int pivot = partition(arr, low_idx, high_idx);

    quick_sort(arr, low_idx, pivot - 1);
    quick_sort(arr, pivot + 1, high_idx);
}

int main() {
    vector<int> v = {3, 5, 1, 1, 9, 2, 7};

    quick_sort(v, 0, v.size() - 1);

    printVector(v);
    return 0;
}
