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
vector<T> counting_sort(vector<T> & arr) {
    int max_num = *max_element(arr.begin(),arr.end());

    vector<T> count_vec(max_num+1,0);

    for (const T el: arr) {
        ++count_vec[el];
    }

    vector<T> result;

    for (int i = 0; i < max_num + 1; ++i) {
        for (int j = 0; j < count_vec[i]; ++j) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    vector<int> v = {3, 5, 1, 9, 2, 7};

    vector<int> sorted = counting_sort(v);
    printVector(sorted);
    return 0;
}