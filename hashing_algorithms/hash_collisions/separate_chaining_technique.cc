/*
Separate chaining resolves hash collisions by storing multiple elements that hash to the same index
                in a linked list or another container at that index.
            It’s commonly used in hash tables where collisions are frequent.
*/
#include <iostream>
#include <vector>
using namespace std;

template <typename T>

struct Node {

    T data;

    Node<T>* next = nullptr;

};

template <typename T>

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

    }

    void insert_node_at_end(T data) {

        Node<T>* new_node = new Node<T>({data});

        if (head == nullptr) {

            head = new_node;

            tail = new_node;

            return;

        }

        tail->next = new_node;
        tail = tail->next;

    }

    void display() {

        Node<T>* current = head;

        while (current != nullptr) {

            cout << current->data << "->";

            current = current->next;

        }

        cout << "nullptr\n";

    }


    bool is_empty() {
        return (head == nullptr);
    }


  private:
    Node<T>* head {nullptr};
    Node<T>* tail {nullptr};
};

class HashData {
public:

    HashData(): table(10, nullptr) {

    }

    ~HashData() {

        for(auto& entry: table) {
            delete entry;
        }
    }

    int hash_function(int key) {
        return key % 10;
    }

    void put(int key) {

        int hash_value = hash_function(key);

        if(!table[hash_value])

            table[hash_value] = new LinkedList<int>();

        table[hash_value]->insert_node_at_end(key);

    }

    void display() {

        for(int i = 0; i < table.size(); ++i) {
            cout << i << " : ";
            if(!table[i])
                cout << "nullptr\n";
            else
                table[i]->display();
        }
    }

private:
    vector<LinkedList<int>*> table;
};

int main() {

    vector<int> keys {12, 17, 15, 4, 27, 14, 37};
    HashData hash1;

    for(auto key: keys)
        hash1.put(key);

    hash1.display();

    return 0;

}