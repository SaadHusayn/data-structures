#include<iostream>
using namespace std;

int main(){
    cout<<"To efficiently store and present this data, i will employ jagged array structure"<<endl;

    string **seating;
    int rows = 0;

    cout<<"Enter the rows in the hall: ";
    cin>>rows;

    seating = new string*[rows];

    for(auto i=0;i<rows;i++){
        int capacity;
        cout<<"\nEnter the capacity of row "<<i+1<<": ";
        cin>>capacity;
        
        seating[i] = new string[capacity];
        for(auto j=0;j<capacity;j++){
            cout<<"Enter the name of attendee that will sit on row "<<i+1<<" seat "<<j+1<<": ";
            cin>>seating[i][j];
        }
    }
}