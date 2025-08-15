/*
Stack is a last-in, first-out (LIFO) structure where elements are added and removed from the top,
     commonly used in function calls, undo features, and expression evaluation.
*/
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

        void insert_node_at_end(T data) {
            Node<T>* new_node = new Node<T>;
            new_node->data = data;

            if (head == nullptr) {
                head = new_node;
                tail = new_node;
                count++;
                return;
            }

            tail->next = new_node;
            tail = new_node;
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
        Node<T>* tail = {nullptr};
        int count = {0};
};

template<typename T>
class Queue {
private:
    LinkedList<T> linked_list;
public:
    Queue() = default;
    ~Queue() = default;

    bool is_empty() {
        return (linked_list.count_elements() == 0);
    }

    void enqueue(T item) {
        linked_list.insert_node_at_end(item);
    }

    void dequeue() {
        if (!is_empty()) {
            linked_list.delete_first_node();
        }
    }

    T peek() {
        return linked_list.get_first_element();
    }

    void print_queue() {
        linked_list.display();
    }
};

int main() {
    Queue<int> queue1;

    queue1.enqueue(10);
    queue1.enqueue(20);
    queue1.enqueue(30);
    queue1.enqueue(40);
    queue1.enqueue(50);

    cout << "Queue after enqueue operations: ";
    queue1.print_queue();

    cout << "Peek the queue: " << queue1.peek() << "\n";

    queue1.dequeue();
    queue1.dequeue();

    cout << "Queue after 2 dequeue() operations: ";
    queue1.print_queue();

    cout << "Check if queue is empty: " << queue1.is_empty() << "\n";


    return 0;
}