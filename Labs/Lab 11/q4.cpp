#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Leaderboard {
    struct Player {
        string id;
        int score;
        bool isDeleted;
        Player(const string& pid, int sc) : id(pid), score(sc), isDeleted(false) {}
    };

    vector<Player*> table;
    int size, count;

    int hashFunction(const string& id) {
        unsigned long hash = 5381;
        for (char c : id) {
            hash = ((hash << 5) + hash) + c;
        }
        return hash % size;
    }

    void rehash() {
        int oldSize = size;
        size *= 2;
        vector<Player*> oldTable = table;

        table = vector<Player*>(size, nullptr);
        count = 0;

        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i] && !oldTable[i]->isDeleted) {
                insert(oldTable[i]->id, oldTable[i]->score);
                delete oldTable[i];
            }
        }
    }

public:
    Leaderboard(int s) : size(s), count(0), table(s, nullptr) {}

    void insert(const string& id, int score) {
        if (count * 1.0 / size > 0.7) {
            rehash();
        }

        int index = hashFunction(id);
        int i = 0;

        while (table[index] && !table[index]->isDeleted && table[index]->id != id) {
            i++;
            index = (index + i * i) % size;
        }

        if (!table[index] || table[index]->isDeleted) {
            table[index] = new Player(id, score);
            count++;
        } else {
            table[index]->score = score;
        }
    }

    void updateScore(const string& id, int delta) {
        int index = hashFunction(id);
        int i = 0;

        while (table[index]) {
            if (!table[index]->isDeleted && table[index]->id == id) {
                table[index]->score += delta;
                return;
            }
            i++;
            index = (index + i * i) % size;
        }

        cout << "Player ID not found!" << endl;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] && !table[i]->isDeleted) {
                cout << i << ": " << table[i]->id << " -> " << table[i]->score << endl;
            } else {
                cout << i << ": empty" << endl;
            }
        }
    }
};

int main() {
    Leaderboard leaderboard(7);

    leaderboard.insert("player1", 100);
    leaderboard.insert("player2", 200);
    leaderboard.insert("player3", 150);
    leaderboard.insert("player4", 180);
    leaderboard.insert("player5", 90);

    cout << "Initial Leaderboard:" << endl;
    leaderboard.display();

    leaderboard.updateScore("player3", 50);
    leaderboard.updateScore("player1", -30);

    cout << "\nUpdated Leaderboard:" << endl;
    leaderboard.display();

    leaderboard.insert("player6", 210);
    leaderboard.insert("player7", 300);

    cout << "\nLeaderboard after Rehashing:" << endl;
    leaderboard.display();

    return 0;
}
