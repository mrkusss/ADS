/*
A traversal is a systematic way of visiting all the nodes (or elements) of a data structure, 
    like a tree or graph, exactly once, so you can perform some operation on each node

Preorder Traversal:
    How it works:
        -> Step 1: Visit the current node → record its value.
        -> Step 2: Recursively visit all children in the order they appear.
    Order: Root → Children (left to right)

Postorder Traversal:
    How it works
        -> Step 1: Recursively visit all children first.
        -> Step 2: Visit the current node after its children.
    Order: Children → Root

Breadth-First Traversal (Level-Order):
    How it works:
        -> Step 1: Start from the root and add it to a queue.
        -> Step 2: Repeatedly remove the front node from the queue, visit it, and enqueue all its children.
        -> Step 3: Continue until the queue is empty.
    Order: Level by level, left to right per level.
*/
#include <iostream>
#include <vector>
#include <queue>
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

    void preorder_traversal(TreeNode<T>* node, vector<T>& traversal) {
        if (!node) return;
        traversal.push_back(node->data);
        for (const auto& child: node->children) {
            preorder_traversal(child, traversal);
        }
    }

    void postorder_traversal(TreeNode<T>* node, vector<T>& traversal) {
        if (!node) return;
        for (const auto& child: node->children) {
            postorder_traversal(child, traversal);
        }
        traversal.push_back(node->data);
    }

    void breadth_first_traversal(vector<T>& traversal) {
        if (!root) return;
        queue<TreeNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            auto current_node = q.front();
            q.pop();
            traversal.push_back(current_node->data);

            for(const auto child: current_node->children) {
                q.push(child);
            }
        }
    }

    TreeNode<T>* root {nullptr};
};


int main() {
    TreeNode<char>* A = new TreeNode<char>('A');
    TreeNode<char>* B = new TreeNode<char>('B');
    TreeNode<char>* C = new TreeNode<char>('C');
    TreeNode<char>* D = new TreeNode<char>('D');
    TreeNode<char>* E = new TreeNode<char>('E');
    TreeNode<char>* F = new TreeNode<char>('F');
    TreeNode<char>* G = new TreeNode<char>('G');

    A->add_child({B, C, D});
    B->add_child({E, F});
    E->add_child({G});

    Tree<char> general_tree = Tree<char>(A);

    vector<char> traversal1;
    cout << "Preorder Traversal: ";
    general_tree.preorder_traversal(general_tree.root, traversal1);
    for(const auto& item: traversal1) {
        cout << item << " ";
    }
    cout << "\n";

    vector<char> traversal2;
    cout << "Postorder Traversal: ";
    general_tree.postorder_traversal(general_tree.root, traversal2);
    for(const auto& item: traversal2) {
        cout << item << " ";
    }
    cout << "\n";

    vector<char> traversal3;
    cout << "Breadth-First Traversal: ";
    general_tree.breadth_first_traversal(traversal3);
    for(const auto& item: traversal3) {
        cout << item << " ";
    }
    cout << "\n";

    return 0;
}