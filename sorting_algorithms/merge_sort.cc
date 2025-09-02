/*
Merge sort is a divide-and-conquer algorithm that recursively splits an array into halves,
                sorts them, and then merges the sorted halves.
    It is commonly used in large datasets and applications requiring stable sorting.
*/
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
void merge_sort(vector<T>& arr, int start_idx, int middle_idx, int end_idx) {
    vector<T> merged;
    int right_idx = middle_idx;
    int left_idx = start_idx;

    while (left_idx < middle_idx && right_idx <= end_idx) {
        if (arr[left_idx] <= arr[right_idx]) {
            merged.push_back(arr[left_idx]);
            ++left_idx;
        } else {
            merged.push_back(arr[right_idx]);
            ++right_idx;
        }
    }

    while (left_idx < middle_idx) {
        merged.push_back(arr[left_idx]);
        ++left_idx;
    }

    while (right_idx <= end_idx) {
        merged.push_back(arr[right_idx]);
        ++right_idx;
    }

    for (int i = 0; i < merged.size(); ++i) {
        arr[start_idx + i] = merged[i];
    }
}

template<typename T>
void merge(vector<T>& arr, int start_idx, int end_idx) {
    if (start_idx >= end_idx) {
        return;
    }

    int middle_idx = start_idx + (end_idx - start_idx + 1) / 2;

    merge(arr, start_idx, middle_idx - 1);
    merge(arr, middle_idx, end_idx);
    merge_sort(arr, start_idx, middle_idx, end_idx);
}

int main() {
    vector<int> v = {3, 5, 1, 9, 2, 7};

    merge(v, 0, v.size() - 1);
    printVector(v);
    return 0;
}
