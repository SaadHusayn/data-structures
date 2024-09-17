// Develop C++ solution such that day month and year are taken as input for 5 records and perform Sorting
// Dates based on year using Selection Sort. Note: Input must be taken from user.
// [Hint: Struct or Class can be used]
// It`s not strictly necessary to take inputs in the format as shown in example, but, the output should be
// in the given format.

#include<iostream>
using namespace std;

#define N 5

class Date{
    public:
    int day, month, year;
};

bool isLess(Date D1, Date D2){
    if(D1.year<D2.year) return true;
    else if (D1.year==D2.year){
        if(D1.month<D2.month) return true;
        else if(D1.month==D2.month){
            return D1.day<D2.day;

        }
    }

    return false;
}

void swapDates(Date &D1, Date &D2){
    auto temp = D1;
    D1 = D2;
    D2 = temp;
}

void sortDates(Date *Dates){
    //selection sort
    for(auto i=0;i<N-1;i++){
        auto index = i;
        for(auto j=i+1;j<N;j++){
            if(isLess(Dates[j], Dates[index])) index = j;
        }

        swapDates(Dates[i], Dates[index]);
    }
}

void printDates(Date *Dates){
    cout<<endl;
    for(auto i=0;i<N;i++){
        cout<<Dates[i].day<<'/'<<Dates[i].month<<'/'<<Dates[i].year<<endl;
    }
}

int main(){
    Date Dates[N];

    cout<<"Enter 5 Dates: "<<endl;
    cin>>Dates[0].day>>Dates[0].month>>Dates[0].year;
    cin>>Dates[1].day>>Dates[1].month>>Dates[1].year;
    cin>>Dates[2].day>>Dates[2].month>>Dates[2].year;
    cin>>Dates[3].day>>Dates[3].month>>Dates[3].year;
    cin>>Dates[4].day>>Dates[4].month>>Dates[4].year;

    sortDates(Dates);

    printDates(Dates);
}