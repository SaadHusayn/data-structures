#include<iostream>
using namespace std;

class Document{
    public:
    Document(){
        content = new string;
        *content="";
    }
    Document(string _content){
        content = new string;
        *content = _content;
    }
    ~Document(){
        delete content;
    }
    Document(Document& Obj){
        content = new string;
        *content = *(Obj.content);
    }
    Document& operator=(const Document& Obj){
        *(this->content) = *(Obj.content);
        return *this;
    }
    void setContent(string _content){
        *content = _content;
    }
    void displayContent(){
        cout<<*content<<endl;
    }
    private:
    string *content;
};

int main(){
    Document D1("This is the content of original document");
    D1.displayContent();

    Document D2(D1);
    D2.displayContent();
    Document D3;
    D3 = D1;
    D3.displayContent();

    D1.setContent("This is the modified content of original document");
    D1.displayContent();

    D2.displayContent();

    D3.displayContent();


}