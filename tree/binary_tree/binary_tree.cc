#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class BinaryTreeNode {
public:
    BinaryTreeNode(T val): data(val) {
        cout << "Node was succesfully created!\n";
    }

    void add_left_child(BinaryTreeNode<T>* val) {
        left_child = val;
        cout << "Left child was succesfully added";
    }

    void add_right_child(BinaryTreeNode<T>* val) {
        right_child = val;
        cout << "Right child was succesfully added";
    }

    T data;
    BinaryTreeNode<T>* left_child;
    BinaryTreeNode<T>* right_child;
};

template<typename T>
class BinaryTree {
public:
    BinaryTree(BinaryTreeNode<T>* node = nullptr): root(node) {
        cout << "Binary Tree was succesfully created!\n";
    }

    void print_path(BinaryTreeNode<T>* currentNode, vector<T> path) {
        if (!currentNode) {
            return;
        }

        path.push_back(currentNode->data);

        if (!currentNode->left_child && !currentNode->right_child) {
            for (int i : path) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            print_path(currentNode->left_child,path);
            print_path(currentNode->right_child,path);
        }
    }

    BinaryTreeNode<T>* root;
};

int main() {
    vector<int> values {1, 2, 3, 4, 5, 6, 7};
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(values[0]);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(values[1]);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(values[2]);
    BinaryTreeNode<int>* node3 = new BinaryTreeNode<int>(values[3]);
    BinaryTreeNode<int>* node4 = new BinaryTreeNode<int>(values[4]);
    BinaryTreeNode<int>* node5 = new BinaryTreeNode<int>(values[5]);
    BinaryTreeNode<int>* node6 = new BinaryTreeNode<int>(values[6]);

    root->add_left_child(node1);
    root->add_right_child(node2);
    node1->add_left_child(node3);
    node1->add_right_child(node4);
    node2->add_left_child(node5);
    node2->add_right_child(node6);

    BinaryTree<int> tree = BinaryTree<int>(root);
    vector<int> paths;
    tree.print_path(tree.root, paths);

    return 0;
}