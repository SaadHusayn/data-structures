#include <iostream>
#include <iomanip> // For formatting
using namespace std;

int main() {
    // Table Header
    cout << left << setw(15) << "Name" 
         << setw(10) << "Age" 
         << setw(15) << "Department" 
         << setw(10) << "GPA" << endl;

    // Table Separator
    cout << string(50, '-') << endl;

    // Table Rows
    cout << left << setw(15) << "Alice" 
         << setw(10) << 22 
         << setw(15) << "Computer Sci" 
         << setw(10) << fixed << setprecision(2) << 3.8 << endl;

    cout << left << setw(15) << "Bob" 
         << setw(10) << 19 
         << setw(15) << "Mathematics" 
         << setw(10) << fixed << setprecision(2) << 3.6 << endl;

    cout << left << setw(15) << "Charlie" 
         << setw(10) << 21 
         << setw(15) << "Physics" 
         << setw(10) << fixed << setprecision(2) << 3.9 << endl;

    return 0;
}
