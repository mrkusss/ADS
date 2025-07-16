#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class BinaryTreeNode {
public:

    BinaryTreeNode(T val) : data(val) {}

    void add_left_child(BinaryTreeNode<T>* node) {
        this->left = node;
    }

    void add_right_child(BinaryTreeNode<T>* node) {
        this->right = node;
    }

    T data;
    BinaryTreeNode<T>* left {nullptr};
    BinaryTreeNode<T>* right {nullptr};
};

template<typename T>
class BinaryTree {
public:

    BinaryTree(BinaryTreeNode<T>* root_node = nullptr) : root(root_node) {}

    void inorder_traversal(BinaryTreeNode<T>* node, vector<T>& traversal) {
        if (node) {
            inorder_traversal(node->left, traversal);
            traversal.push_back(node->data);
            inorder_traversal(node->right, traversal);
        }
    }

    int evaluate(BinaryTreeNode<T>* node) {
        if (!node) {
            return 0;
        }

        if (!node->left && !node->right) {
            return stoi(node->data);
        }

        int left_val = evaluate(node->left);
        int right_val = evaluate(node->right);

        if (node->data == "+") {
            return left_val + right_val;
        }
        else if (node->data == "-") {
            return left_val - right_val;
        }
        else if (node->data == "*") {
            return left_val * right_val;
        }
        else if (node->data == "/") {
            // Assume no division by zero
            return left_val / right_val; 
        }

        return 0;
    }

    BinaryTreeNode<T>* root;
};

int main() {

    BinaryTreeNode<string>* root_node = new BinaryTreeNode<string>("-");
    BinaryTreeNode<string>* node1 = new BinaryTreeNode<string>("/");
    BinaryTreeNode<string>* node2 = new BinaryTreeNode<string>("+");
    BinaryTreeNode<string>* node3 = new BinaryTreeNode<string>("*");
    BinaryTreeNode<string>* node4 = new BinaryTreeNode<string>("+");
    BinaryTreeNode<string>* node5 = new BinaryTreeNode<string>("*");
    BinaryTreeNode<string>* node6 = new BinaryTreeNode<string>("6");
    BinaryTreeNode<string>* node7 = new BinaryTreeNode<string>("+");
    BinaryTreeNode<string>* node8 = new BinaryTreeNode<string>("3");
    BinaryTreeNode<string>* node9 = new BinaryTreeNode<string>("-");
    BinaryTreeNode<string>* node10 = new BinaryTreeNode<string>("2");
    BinaryTreeNode<string>* node11 = new BinaryTreeNode<string>("3");
    BinaryTreeNode<string>* node12 = new BinaryTreeNode<string>("-");
    BinaryTreeNode<string>* node13 = new BinaryTreeNode<string>("3");
    BinaryTreeNode<string>* node14 = new BinaryTreeNode<string>("1");
    BinaryTreeNode<string>* node15 = new BinaryTreeNode<string>("9");
    BinaryTreeNode<string>* node16 = new BinaryTreeNode<string>("5");
    BinaryTreeNode<string>* node17 = new BinaryTreeNode<string>("7");
    BinaryTreeNode<string>* node18 = new BinaryTreeNode<string>("4");

    root_node->add_left_child(node1);
    root_node->add_right_child(node2);
    node1->add_left_child(node3);
    node1->add_right_child(node4);
    node2->add_left_child(node5);
    node2->add_right_child(node6);
    node3->add_left_child(node7);
    node3->add_right_child(node8);
    node4->add_left_child(node9);
    node4->add_right_child(node10);
    node5->add_left_child(node11);
    node5->add_right_child(node12);
    node7->add_left_child(node13);
    node7->add_right_child(node14);
    node9->add_left_child(node15);
    node9->add_right_child(node16);
    node12->add_left_child(node17);
    node12->add_right_child(node18);

    BinaryTree<string> tree(root_node);
    vector<string> traversal;
    tree.inorder_traversal(tree.root, traversal);
    int result = tree.evaluate(tree.root);

    cout << "Inorder Traversal: ";
    for (const string& data : traversal) {
        cout << data << " ";
    }
    cout << endl;

    cout << "Expression Evaluation Result: " << result << endl;

    return 0;
}