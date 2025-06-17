#include <iostream>
#include <list>
#include <string>
#include <optional>

using namespace std;


template <typename T1, typename T2>
struct KeyValuePair {
    T1 key;
    T2 value;
};


template<typename T1, typename T2>
class HashMap {
private:

    static const int tableSize = 128;

    list<KeyValuePair<T1, T2>>* table;

public:
    HashMap() {
        table = new std::list<KeyValuePair<T1, T2>>[tableSize];
    }

    ~HashMap() {
        delete[] table;
    }

    int hash(const T1& key) {
        return key % tableSize;
    }

    void insert(const T1 key, const T2 value) {
        int index = hash(key);
        for (KeyValuePair<T1, T2>& pair: table[index]) {

            if (pair.key == key) {
                pair.value = value;
             	  return;
            }
        }

        table[index].push_back(KeyValuePair<T1, T2>{key, value});
    }

    optional<T2> get(const T1& key) {
        int index = hash(key);
        for (const KeyValuePair<T1, T2>& pair : table[index]) {
            if (pair.key == key) {
                return pair.value;
            }
        }
        return {};
    }


    void remove(const T1& key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};

int main() {
    HashMap<int, string> Student;

    Student.insert(1, "James");
    Student.insert(2, "Paul");
    Student.insert(3, "Mira");

    cout << "Student with ID 1 is " << Student.get(1).value() << endl;
    cout << "Student with ID 2 is " << Student.get(2).value() << endl;

    Student.remove(2);

    return 0;
}