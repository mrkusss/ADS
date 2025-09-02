/*
A Binary Search Tree is a type of binary tree with the following properties:

    Each node has at most two children (left and right).

    For each node:

        -> The left child contains only values smaller than the parent.

        -> The right child contains only values greater than the parent.

    No duplicates (in standard BST).

This structure allows fast search, insertion, and deletion in average O(log n) time (but can degrade to O(n) if the tree becomes unbalanced).
*/
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class BinarySearchTreeNode {
public:

    T data;
    BinarySearchTreeNode<T>* left {nullptr};
    BinarySearchTreeNode<T>* right {nullptr};

    BinarySearchTreeNode(T data_value) : data(data_value) {}
};

template<typename T>
class BinarySearchTree {
public:
    BinarySearchTreeNode<T>* root {nullptr};

    BinarySearchTree() = default;

    void insert_node(T value, BinarySearchTreeNode<T>* currentNode) {
        if(!currentNode) {
            root = new BinarySearchTreeNode<T>(value);
            return;
        }

        if (value > currentNode->data) {
            if(!currentNode->right) {
                currentNode->right = new BinarySearchTreeNode<T>(value);
            } else {
                insert_node(value, currentNode->right);
            }
        
        }
        else if (value < currentNode->data) {
            if (!currentNode->left) {
                currentNode->left = new BinarySearchTreeNode<T>(value);
            } else {
                insert_node(value, currentNode->left);
            }
        }
    }

    BinarySearchTreeNode<T>* search(T value, BinarySearchTreeNode<T>* currentNode) {
        if (!currentNode) {
            return nullptr;
        }

        if (value == currentNode->data) {
            return currentNode;
        } else if ( value < currentNode) {
            search(value,currentNode->left);
        } else {
            search(value, currentNode->right);
        }
    }

    BinarySearchTreeNode<T>* delete_node(BinarySearchTreeNode<T>* root, T value) {
        if (!root) {
            return root;
        }

        if (value < root->data) {
            root->left = delete_node(root->left, value);
        }
        else if (value > root->data) {
            root->right = delete_node(root->right, value);
        }
        else {
            if (!root->left) {
                BinarySearchTreeNode<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                BinarySearchTreeNode<T>* temp = root->left;
                delete root;
                return temp;
            }

            BinarySearchTreeNode<T>* temp = root->right;

            while (temp && temp->left) {
                temp = temp->left;
            }

            root->data = temp->data;
            root->right = delete_node(root->right,temp->data);

        }
        return root;
    }

    void inorder_traversal(BinarySearchTreeNode<T>* node, vector<T>& traversal) {
        if (!node) {
            return;
        }

        inorder_traversal(node->left, traversal);
        traversal.push_back(node->data);
        inorder_traversal(node->right, traversal);
    }
};

int main() {

    BinarySearchTree<int> bst;
    vector<int> values_to_insert = {1, 2, 3, 4, 5};
    for (int value : values_to_insert) {
        bst.insert_node(value, bst.root);
    }

    cout << "Inorder Traversal After Insertion: ";
    vector<int> in_order;
    bst.inorder_traversal(bst.root, in_order);
    for (int data : in_order) {
        cout << data << " ";
    }
    cout << '\n';

    vector<int> values_to_delete = {2};
    for (int value : values_to_delete) {
        bst.root = bst.delete_node(bst.root, value);
        cout << "Deleted " << value << endl;
    }

    cout << "Inorder Traversal After Deletion: ";
    in_order.clear();
    bst.inorder_traversal(bst.root, in_order);
    for (int data : in_order) {
        cout << data << " ";
    }
    cout << '\n';

    return 0;
}