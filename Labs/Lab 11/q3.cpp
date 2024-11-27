#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

class HashTable {
    struct Node {
        string key;
        vector<string> value;
        Node* next;
        Node(const string& k, const vector<string>& v) : key(k), value(v), next(nullptr) {}
    };

    vector<Node*> table;
    int size;

    int hashFunction(const string& key) {
        unsigned long hash = 5381;
        for (char c : key) {
            hash = ((hash << 5) + hash) + c;
        }
        return hash % size;
    }

public:
    HashTable(int s) : size(s), table(s, nullptr) {}

    void insert(const string& key, const vector<string>& items) {
        int index = hashFunction(key);
        Node* head = table[index];

        while (head) {
            if (head->key == key) {
                for (const string& item : items) {
                    if (find(head->value.begin(), head->value.end(), item) == head->value.end()) {
                        head->value.push_back(item);
                    }
                }
                return;
            }
            head = head->next;
        }

        Node* newNode = new Node(key, items);
        newNode->next = table[index];
        table[index] = newNode;
    }

    vector<string> get(const string& key) {
        int index = hashFunction(key);
        Node* head = table[index];

        while (head) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return {};
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* head = table[i];
            while (head) {
                cout << head->key << " -> [ ";
                for (const string& item : head->value) {
                    cout << item << " ";
                }
                cout << "] ";
                head = head->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable recommendations(10);
    recommendations.insert("Laptop", {"Mouse", "Keyboard", "Bag"});
    recommendations.insert("Phone", {"Charger", "Case", "Headphones"});
    recommendations.insert("Laptop", {"Headphones", "Stand"});

    cout << "Recommendations:" << endl;
    recommendations.display();

    cout << "\nRecommendations for 'Laptop':" << endl;
    vector<string> recs = recommendations.get("Laptop");
    for (const string& item : recs) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
