#include <iostream>
using namespace std;

template <typename T>

struct Node {
    T data;

    Node<T>* prev = nullptr;

    Node<T>* next = nullptr;
};

template <typename T>
class DoublyLinkedList {
  public:

    DoublyLinkedList() = default;

    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << "  ";
            current = current->next;
        }
        cout << "\n";
    }

    void insert_at_end(T data) {
        Node<T>* new_node = new Node<T>({data});
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        ++count;
    }

    void insert_at_beginning(T data) {
        Node<T>* new_node = new Node<T>({data});
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
        ++count;
    }

    void delete_from_beginning() {
        if(head == nullptr)
            return;

        if (head == tail) {
            delete_single_element();
            --count;
            return;

        }

        Node<T>* node_to_delete = head;
        head = head->next;
        head->prev = nullptr;
        delete node_to_delete;
        --count;
     }

     void delete_single_element() {
        if(head == nullptr) return;
        Node<T>* node_to_delete = head;
        head = nullptr;
        tail = nullptr;
        delete node_to_delete;
     }

     void delete_from_end() {
        if (tail == nullptr) {
           return;
        }

        if (head == tail) {
            delete_single_element();
            --count;
            return;
        }

        Node<T>* node_to_delete = tail;
        tail = tail->prev;
        tail->prev = node_to_delete->prev;
        tail->next = nullptr;
        delete node_to_delete;
        --count;
     }

  private:
    Node<T>* head {nullptr};
    Node<T>* tail {nullptr};
    int count {0};
};

template<typename T>
class Deque {
    public:

        Deque() = default;
        ~Deque() = default;

        void add_rear(T item)  {
            doubly_linked_list.insert_at_end(item);
        }

        void add_front(T item) {
            doubly_linked_list.insert_at_beginning(item);
        }

        void remove_front() {
            doubly_linked_list.delete_from_beginning();
        }

        void remove_rear() {
            doubly_linked_list.delete_from_end();
        }

        void print_deque() {
             doubly_linked_list.display();
        }

    private:
        DoublyLinkedList<T> doubly_linked_list;
};


int main(){

    Deque<int> d;

    cout << "Empty deque: ";

    d.print_deque();
    d.add_rear(8);
    d.add_rear(5);

    cout << "After inserting from rear: ";

    d.print_deque();
    d.add_front(7);
    d.add_front(10);

    cout << "After inserting from front: ";

    d.print_deque();
    d.remove_rear();

    cout << "After removing from rear: ";

    d.print_deque();
    d.remove_front();

    cout << "After removing from front: ";

    d.print_deque();

    return 0;
}