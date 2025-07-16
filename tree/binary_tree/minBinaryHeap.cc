#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
public:
    MinHeap() {}
    int size() {
        return heap.size();
    }

    bool is_empty() {
        return heap.size() == 0;
    }

    string to_string() {
        string result = "[";

        for (size_t i = 0; i < heap.size(); ++i) {
            result += std::to_string(heap[i]);
            if (i != heap.size() - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }

    void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    int left_child(int index) {
        return 2 * index + 1;
    }

    int right_child(int index) {
        return 2 * index + 2;
    }

    bool has_parent(int index) {
        return parent(index) >= 0;
    }

    bool has_left_child(int index) {
        return left_child(index) < heap.size();
    }

    bool has_right_child(int index) {
        return right_child(index) < heap.size();
    }

    void set_heap(const vector<int>& elements) {
        heap = elements;
    }
};

int main() {
    vector<int> static_heap = {3, 1, 6, 5, 2, 4};

    MinHeap min_heap;

    min_heap.set_heap(static_heap);

    cout << "Heap: " << min_heap.to_string() << endl; // [3, 1, 6, 5, 2, 4]
    cout << "Size: " << min_heap.size() << endl; // 6
    cout << "Is empty: " << (min_heap.is_empty() ? "Yes" : "No") << endl; // No

    int index = 1;

    cout << "Parent of node at index " << index << ": " << min_heap.parent(index) << endl; // 0
    cout << "Left child of node at index " << index << ": " << min_heap.left_child(index) << endl; // 3
    cout << "Right child of node at index " << index << ": " << min_heap.right_child(index) << endl; // 3

    return 0;
}