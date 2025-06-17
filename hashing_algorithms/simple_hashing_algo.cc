#include <iostream>
#include <vector>
using namespace std;

class HashData {
public:
    HashData(): table(size, -1) {
     }

    int hash_function(int key) {
        return key % size;
    }

    void put(int key) {
        int hash_value = hash_function(key);
        table[hash_value] = key;

        int sum = 0;
        for(auto data: table) {
            if(data != -1)
                ++sum;
        }
        float current_lf = sum *1.0f / size;

        if(current_lf >= lf_threshold)
            rehash();

    }

    void display() {
        for(int i = 0; i < size; ++i)
            cout << i << " : " << table[i] << '\n';
    }

    void rehash() {
        size = size*2;
        vector<int> new_table(size,-1);

        for (auto i: table) {
            if (i!=-1) {
                int hash_value = hash_function(i);
                new_table[hash_value] = i;
            }
        }

        table = new_table;
    }

private:
    int size {5};
    vector<int> table;
    float lf_threshold {0.75};
};

int main() {
    vector<int> keys {24, 8, 42, 5};

    HashData hash1;

    for(auto key: keys)
        hash1.put(key);

    hash1.display();

    return 0;
}