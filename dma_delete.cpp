#include<iostream>
using namespace std;
int main() {
int *ptr = new int(99); // dynamically allocate an integer int
int *otherPtr = ptr; // otherPtr is now pointed at that same memory
// ptr = 0; // ptr is now a nullptr

cout<<ptr<<endl;
cout<<otherPtr<<endl;
cout<<*ptr<<endl;
cout<<*otherPtr<<endl;

delete ptr; // ptr and otherPtr are now dangling pointers.



cout<<ptr<<endl;
cout<<otherPtr<<endl;
cout<<*ptr<<endl;
cout<<*otherPtr<<endl;
// however, otherPtr is still a dangling pointer!
return 0; }