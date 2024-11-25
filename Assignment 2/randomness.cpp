#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string getRandomName() {
    string s = "";
    s.push_back((char)('A' + rand() % 26));
    s.push_back((char)('A' + rand() % 26));
    s.push_back((char)('A' + rand() % 26));
    s.push_back((char)('A' + rand() % 26));
    return s;
}

int main() {
    srand(time(0)); // Seed the random number generator with current time

    for (int i = 0; i < 1000; i++) {
        cout << getRandomName() << endl;
    }

    return 0;
}
