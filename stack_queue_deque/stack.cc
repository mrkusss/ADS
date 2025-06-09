#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
};

template<typename T>
class LinkedList {
    public:
        LinkedList() = default;
        ~LinkedList() {
            Node<T>* current = head;
            while (current) {
                Node<T>* next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
            count = 0;
        }

        void delete_first_node() {
            Node<T>* node_to_delete = head;
            head = head->next;
            delete node_to_delete;
            --count;
        }

        T get_first_element() {
            return head->data;
        }

        void insert_node_at_beginning(T data) {
            Node<T>* new_node = new Node<T>;
            new_node->data = data;
            new_node->next = head;

            head = new_node;
            ++count;
        }

        int count_elements() {
            return count;
        }

        void display() {
            Node<T>* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << "\n";
        }

    private:
        Node<T>* head {nullptr};
        int count = {0};
};

template<typename T>
class Stack {
private:
    LinkedList<T> linked_list;
public:
    Stack() = default;
    ~Stack() = default;

    bool is_empty() {
        return (linked_list.count_elements() == 0);
    }

    void push(T item) {
        linked_list.insert_node_at_beginning(item);
    }

    void pop() {
        if (!is_empty()) {
            linked_list.delete_first_node();
        }
    }

    T peek() {
        return linked_list.get_first_element();
    }

    void print_stack() {
        linked_list.display();
    }
};

int main() {
    Stack<int> stack1;

    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.push(50);

    cout << "Stack after push operations: ";
    stack1.print_stack();

    cout << "Peek the stack: " << stack1.peek() << "\n";

    stack1.pop();
    stack1.pop();

    cout << "Stack after 2 pop() operations: ";
    stack1.print_stack();

    cout << "Check if stack is empty: " << stack1.is_empty() << "\n";

    return 0;
}