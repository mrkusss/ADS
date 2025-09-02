/*
This is an implementation of a binary tree using an array (vector) rather than nodes with pointers.
This is often called a heap-like representation, commonly used for complete binary trees.
    -> Instead of creating separate node objects, the tree is stored in a vector (arr).
    -> The parent-child relationships are determined mathematically using indices.
*/
#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
public:
    BinaryTree() {}

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
        return left_child(index) < arr.size();
    }

    bool has_right_child(int index) {
        return right_child(index) < arr.size();
    }

    void insert(int value) {
        arr.push_back(value);
    }

    void print_tree() {
        for (int value : arr) {
            cout << value << " ";
        }
        cout << endl;
    }


    int get_value_at(int index) {
        return arr[index];
    }

private:
    vector<int> arr;
};

int main() {
    BinaryTree bt;

    for (int i = 0; i < 10; i++) {
        bt.insert(i);
    }

    bt.print_tree();
    cout << endl;

    int index = 3;

    if (bt.has_parent(index)) {
        cout << "Parent of node at index " << index << ": " << bt.get_value_at(bt.parent(index)) << endl;
    }

    if (bt.has_left_child(index)) {
        cout << "Left child of node at index " << index << ": " << bt.get_value_at(bt.left_child(index)) << endl;
    }

    if (bt.has_right_child(index)) {
        cout << "Right child of node at index " << index << ": " << bt.get_value_at(bt.right_child(index)) << endl;
    }
    return 0;
}