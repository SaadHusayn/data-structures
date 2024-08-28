#include <iostream>
using namespace std;

class SLLNode
{

public:
    ~SLLNode()
    {
        delete next;
    }

    SLLNode()
    {
        data = 0;
        next = 0;
    }
    SLLNode(int _data, SLLNode *nextAdd = 0) : data(_data)
    {
        next = nextAdd;
    }

    int data;
    SLLNode *next;
};

int main()
{
    SLLNode *p = new SLLNode(10);

    p->next = new SLLNode(8);

    p->next->next = new SLLNode(50);

}