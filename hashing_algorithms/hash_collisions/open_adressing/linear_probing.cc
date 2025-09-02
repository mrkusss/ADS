/*
Linear probing -> A collision resolution method in hash tables where,
                if a hash index is occupied,
the algorithm checks the next sequential slots until an empty one is found.
*/
#include <iostream>
#include <vector>
using namespace std;

class HashData {
public:

    HashData(): table(10, -1) {
     }


    int hash_function(int key) {
        return key % 10;
    }


    void put(int key) {
        int i = 0;
        int hash_value = hash_function(key);
        while(table[hash_value] != -1) {
            i += 1;
            hash_value = (hash_function(key) + i) % 10;
        }

        table[hash_value] = key;
    }

    void display() {
        for(int i = 0; i < 10; ++i)
            cout << i << " : " << table[i] << '\n';
    }

private:
    vector<int> table;
};

int main() {

    vector<int> keys {12, 17, 15, 4, 27, 14, 37};

    HashData hash1;


    for(auto key: keys)
        hash1.put(key);

    hash1.display();
    return 0;
}