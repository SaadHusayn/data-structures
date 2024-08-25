#include<iostream>
using namespace std;

 int main()
{
int *ptr = new int; // allocate memory
*ptr = 7; // assign value
cout<<*ptr<<endl;
// allocated memory and assign value
int *ptr2 = new int(5);
cout<<*ptr2<<endl;

}
