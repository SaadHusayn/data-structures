#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void splitIPAddress(const string& ip, int octets[4]) {
    stringstream ss(ip);
    string octet;
    int i = 0;
    while (getline(ss, octet, '.')) {
        octets[i++] = stoi(octet);
    }
}

void countingSort(string ipAddresses[], int n, int index) {
    int count[256] = {0};
    string output[n];
    int octets[4];

    for (int i = 0; i < n; ++i) {
        splitIPAddress(ipAddresses[i], octets);
        count[octets[index]]++;
    }

    for (int i = 1; i < 256; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        splitIPAddress(ipAddresses[i], octets);
        output[count[octets[index]] - 1] = ipAddresses[i];
        count[octets[index]]--;
    }

    for (int i = 0; i < n; ++i) {
        ipAddresses[i] = output[i];
    }
}

void radixSort(string ipAddresses[], int n) {
    for (int i = 3; i >= 0; --i) {
        countingSort(ipAddresses, n, i);
    }
}

int main() {
    string ipAddresses[] = {
        "192.168.1.1",
        "10.0.0.2",
        "172.16.0.1",
        "192.168.0.1",
        "10.0.0.1"
    };
    int n = sizeof(ipAddresses) / sizeof(ipAddresses[0]);

    cout << "Initial IP Addresses:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << ipAddresses[i] << endl;
    }

    radixSort(ipAddresses, n);

    cout << "\nSorted IP Addresses:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << ipAddresses[i] << endl;
    }

    return 0;
}
