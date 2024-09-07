#include<iostream>
using namespace std;

class GPA_Of_Core_Courses_Of_Departments{
    float **GPAs;

    //additional attributes that will help in working with jagged array
    string department_names[4];
    int core_courses_count[4];

    public:
    GPA_Of_Core_Courses_Of_Departments(): department_names{"SE", "AI", "CS", "DS"}, core_courses_count{3, 4, 2, 1}{
        GPAs = new float*[4];
        for(auto i=0;i<4;i++){
            GPAs[i] = new float[core_courses_count[i]];
        }
    }

    void getGPAsFromUser(){
        for(auto i=0;i<4;i++){
            cout<<"\nDepartment: "<<department_names[i]<<endl;
            for(auto j=0;j<core_courses_count[i];j++){
                cout<<"Enter GPA of core course "<<j+1<<": ";
                cin>>GPAs[i][j];
            }
        }
    }

    void displayGPAs(){
        for(auto i=0;i<4;i++){
            cout<<"\nDepartment: "<<department_names[i]<<endl;
            for(auto j=0;j<core_courses_count[i];j++){
                cout<<"GPA of core course "<<j+1<<": "<<GPAs[i][j]<<endl;
            }
        }
    }
};

int main(){
    cout<<"To efficiently store and present this data, i will employ jagged array structure"<<endl;

    GPA_Of_Core_Courses_Of_Departments G1;

    G1.getGPAsFromUser();

    G1.displayGPAs();

}