#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HashTable {
    vector<string> table;
    int size;

public:
    HashTable(int s) : size(s), table(s, "") {}

    int customHash(const string& key) {
        unsigned long hash = 5381;
        for (char c : key) {
            hash = ((hash << 5) + hash) + c;
        }
        return hash % size;
    }

    void insertCustom(const string& key) {
        int index = customHash(key);
        while (!table[index].empty()) {
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    int moduloHash(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % size;
    }

    void insertModulo(const string& key) {
        int index = moduloHash(key);
        while (!table[index].empty()) {
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": " << (table[i].empty() ? "empty" : table[i]) << endl;
        }
    }
};

int main() {
    vector<string> names = {"Alice", "Bob", "Charlie", "Dave"};

    HashTable customHT(10), moduloHT(10);

    for (const string& name : names) {
        customHT.insertCustom(name);
    }

    cout << "Hash Table with Custom Hash Function:" << endl;
    customHT.display();

    for (const string& name : names) {
        moduloHT.insertModulo(name);
    }

    cout << "\nHash Table with Modulo Hash Function:" << endl;
    moduloHT.display();

    return 0;
}
