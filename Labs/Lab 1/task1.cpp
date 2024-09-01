#include<iostream>
using namespace std;

class BankAccount{
    private:
    float balance;

    public:
    BankAccount(){
        balance = 100;
    }
    BankAccount(float _balance):balance(_balance){}
    BankAccount(BankAccount &Obj){
        balance = Obj.balance;
    }
    float getBalance(){return balance;}
    void setBalance(float _balance){balance = _balance;}
};

int main(){
    BankAccount account1;
    cout<<"The balance of account1 is "<<account1.getBalance()<<endl;

    BankAccount account2(1000.0);
    cout<<"The balance of account2 is "<<account2.getBalance()<<endl;

    BankAccount account3(account2);
    account3.setBalance(account3.getBalance() - 200);
    cout<<"The balance of account3 is "<<account3.getBalance()<<" and the balance of account2 is "<<account2.getBalance()<<endl;
    
}