#include <iostream>
#include <vector>
using namespace std;

class HashData {
public:
    HashData(): table(10, -1) {
    }

    int hash_function(int key, int i = 0) {
        return (primary_hash_function(key) + i * secondary_hash_function(key)) % 10;
    }


    int primary_hash_function(int key) {
        return key % 10;
    }

    int secondary_hash_function(int key) {
        return (1 + key % 9);
    }

    void put(int key) {
        int i = 0;
        int hash_value = hash_function(key);
        while(table[hash_value] != -1) {

            i += 1;
            hash_value = hash_function(key, i);
        }

        table[hash_value] = key;
    }


    void display() {
        for(int i = 0; i < table.size(); ++i)
            cout << i << " : " << table[i] << '\n';
    }

    pair<int, int> retrieve(int key) {
        int hash_value = hash_function(key);
        int i = 0;
        while(table[hash_value] != -1) {

            if(table[hash_value] == key)
                return {hash_value, key};

            ++i;
            hash_value = hash_function(key, i);
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