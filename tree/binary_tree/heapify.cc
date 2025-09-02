/*
        Heapify is the process of restoring the heap property in a binary heap.
In a MinHeap, the heap property means that every parent node is less than or equal to its children.
In a MaxHeap, the property is the opposite: every parent node is greater than or equal to its children.

If the heap property is violated (for example, after inserting or removing an element), we use heapify to fix it.

Types of heapify:

Heapify Up (a.k.a. Bubble Up or Sift Up)

-> Used when we insert a new element into the heap.
-> The new element is placed at the end of the array (the bottom of the tree).
-> If it violates the heap property (e.g., smaller than its parent in MinHeap), we swap it with the parent.
-> This process continues until the heap property is restored or the element reaches the root.

Heapify Down (a.k.a. Bubble Down or Sift Down)

-> Used when we remove the root element (usually the min or max).
-> The last element in the array is moved to the root.
-> If it violates the heap property (e.g., larger than a child in MinHeap), we swap it with the smaller child.
-> This process continues until the element is in the correct position or becomes a leaf.

There is implemented Heapify Down
*/
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

    void heapify(vector<int>& array) {
        heap = array;
        for (int i = heap.size() - 1; i >= 0; --i) {
            if (has_left_child(i)) {
                heapify_down(i);
            }
        }
    }

    void heapify_down(int index) {
        if (!has_left_child(index)) {
            return;
        }
        int smaller_child_index = left_child(index);
        if (has_right_child(index) && heap[right_child(index)] < heap[smaller_child_index]) {
            smaller_child_index = right_child(index);
        }
        if (heap[index] <= heap[smaller_child_index]) {
            return;
        }
        swap(index, smaller_child_index);
        heapify_down(smaller_child_index);
    }

    void heapify_up(int index) {
        if (has_parent(index)) {
            int parent_index = parent(index);
            if (heap[index] < heap[parent_index]) {
                swap(index, parent_index);
                heapify_up(parent_index);
            }
        }
    }

    void insert(int value) {
        heap.push_back(value);
        heapify_up(size() - 1);
    }

    int extract_min() {
        int min = heap[0];
        if (size() == 1) {
            heap.clear();
            return min;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
        return min;
    }
    
    int peek(){
        return heap[0];
    }
};

int main() {
    MinHeap heap;

    heap.insert(10);
    heap.insert(40);
    heap.insert(20);
    heap.insert(30);
    cout << heap.to_string() << endl;

    cout << "Root: " << heap.peek() << endl;
    cout << "Min Element: " << heap.extract_min() << endl;
    cout << heap.to_string() << endl;   
    return 0;
}