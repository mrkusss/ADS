/*
                Quadratic probing -> A collision resolution method in hash tables where,
                                    if a hash index is occupied, 
the algorithm checks slots at increasing quadratic intervals (e.g., 1², 2², 3²…) until an empty one is found.
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
            hash_value = (hash_function(key) + i*i) % 10;
        }

        table[hash_value] = key;
    }


    void display() {
        for(int i = 0; i < 10; ++i)
            cout << i << " : " << table[i] << '\n';
    }

    pair<int, int> retrieve(int item) {
        int hash_value = hash_function(item);
        int i = 0;

        while(table[hash_value] != -1) {

            if(table[hash_value] == item)
                return {hash_value, table[hash_value]};

            ++i;
            hash_value = (hash_function(item) + i*i) % 10;
        }

        return {hash_value, -1};
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

    cout << "\nRetrieving Values: \n";

    pair<int, int> retrieve_27 = hash1.retrieve(27);
    cout << "hash_value: " << retrieve_27.first << ", key: " << retrieve_27.second << '\n';
    pair<int, int> retrieve_13 = hash1.retrieve(13);
        cout << "hash_value: " << retrieve_13.first << ", key: " << retrieve_13.second << '\n';

    return 0;
}