#include<iostream>
using namespace std;

class Exam{
    public:
    Exam(string _student_name="", string _exam_date="", float _exam_score=0.0):student_name(_student_name), exam_date(_exam_date), exam_score(_exam_score){}

    void setstudent_name(string _student_name){
        student_name = _student_name;
    }

    void setexam_date(string _exam_date){
        exam_date = _exam_date;
    }

    void setexam_score(float _exam_score){
        exam_score = _exam_score;
    }

    void displayExamDetails(){
        cout<<"Student Name: "<<student_name<<endl;
        cout<<"Exam Date: "<<exam_date<<endl;
        cout<<"Exam Score: "<<exam_score<<endl;
    }
    private:
    string student_name, exam_date;
    float exam_score;
};

int main(){
    Exam Exam1("Saad Hussain", "09/01/2024", 100.0);
    Exam Exam2(Exam1);

    cout<<"The details of first object are:"<<endl;
    Exam1.displayExamDetails();

    cout<<"\nThe details of second object which is created by copy constructor using first object are:"<<endl;
    Exam2.displayExamDetails();

    cout<<"\nTechnically default constructor is working as expected, there is no issues in it. However, in real life we dont want two exam objects to be off same student name and same score, so in this case we have to create a user defined constructor to differentiate between two objects."<<endl;
}