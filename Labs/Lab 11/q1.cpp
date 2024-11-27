#include <iostream>
#include <vector>
#include<string>
using namespace std;

class HashTable {
    vector<int> table;
    int size;

public:
    HashTable(int s) : size(s), table(s, -1) {}

    void insert(int key) {
        int index = key % size;
        while (table[index] != -1) {
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = key % size;
        int startIndex = index;
        while (table[index] != -1) {
            if (table[index] == key) return true;
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": " << (table[i] == -1 ? "empty" : to_string(table[i])) << endl;
        }
    }
};

int main() {
    HashTable ht(10);
    ht.insert(23);
    ht.insert(33);
    ht.insert(43);
    ht.insert(53);
    ht.insert(63);
    ht.insert(73);

    cout << "Hash Table:" << endl;
    ht.display();

    cout << "Search 33: " << (ht.search(33) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (ht.search(99) ? "Found" : "Not Found") << endl;

    return 0;
}
