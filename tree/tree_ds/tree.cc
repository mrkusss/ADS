#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
public:
    TreeNode(T val): data(val) {
        cout << "Node " << data << " was created\n";
    }

    void add_child(vector<TreeNode<T>*> child_arr) {
        children = child_arr;
        cout << "Nodes ";

        for(const auto& item: children) {
            cout << item->data << " ";
        }
        cout << "were added as children to Node " << data << "\n";
    }

    T data;
    vector<TreeNode<T>*> children;

};

template <typename T>
class Tree {
public:

    Tree(TreeNode<T>* root_node): root(root_node) {
        cout << "A tree was created\n";
    };

    TreeNode<T>* root {nullptr};

};


int main() {

    TreeNode<string>* root = new TreeNode<string>("Book");

    TreeNode<string>* child1 = new TreeNode<string>("1");
    TreeNode<string>* child2 = new TreeNode<string>("2");
    TreeNode<string>* child3 = new TreeNode<string>("3");

    TreeNode<string>* child1_1 = new TreeNode<string>("1.1");
    TreeNode<string>* child1_2 = new TreeNode<string>("1.2");
    TreeNode<string>* child1_3 = new TreeNode<string>("1.3");
    TreeNode<string>* child1_4 = new TreeNode<string>("1.4");
    TreeNode<string>* child2_1 = new TreeNode<string>("2.1");
    TreeNode<string>* child3_1 = new TreeNode<string>("3.1");
    TreeNode<string>* child3_2 = new TreeNode<string>("3.2");
    TreeNode<string>* child3_3 = new TreeNode<string>("3.3");

    root->add_child({child1, child2, child3});

    child1->add_child({child1_1, child1_2, child1_3, child1_4});
    child2->add_child({child2_1});
    child3->add_child({child3_1, child3_2, child3_3});

    Tree<string> general_tree = Tree<string>(root);
    return 0;

}