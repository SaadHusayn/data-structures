#include <iostream>
#include <cassert>
#include "SLL.h"
using namespace std;

Node *evenOdd(Node *head)
{

    Node *last_even = new Node();
    last_even = 0;

    bool hasOdd = false;

    for (auto i = head; i != nullptr; i = i->next)
    {

        if (i->val % 2)
        {
            hasOdd = true;
        }

        if ((i->val % 2) == 0)
        {
            last_even = i;
        }
    }

    // list is either complete even or complete odd
    if (hasOdd==false || (last_even == nullptr))
        return head;

    // remove all the odd elements from the start
    auto ptr = last_even;
    while (head->val % 2)
    {
        auto temp1 = head;
        head = head->next;
        temp1->next = ptr->next;
        ptr->next = temp1;
        ptr = ptr->next;
    }


    //last even sa pehle wala odds ko aagay phekte jao
    auto prev = head;
    auto curr = head->next;
    while (curr != last_even)
    {
        if (curr->val % 2)
        {
            prev->next = curr->next;
            curr->next = ptr->next;
            ptr->next = curr;
            ptr = ptr->next;
            curr = prev->next;
        }
        else
        {
            curr = curr->next;
            prev = prev->next;
        }
    }

    return head;
}

int main()
{
    Node *n1 = new Node{17, new Node{15, new Node{8, new Node{12, new Node{10, new Node{5, new Node{4, new Node{1, new Node{7, new Node{6, nullptr}}}}}}}}}};

    Node *n2 = new Node{8, new Node{12, new Node{10, new Node{5, new Node{4, new Node{1, {new Node{6, nullptr}}}}}}}};

    Node *n3 = new Node{8, new Node{12, new Node{10, nullptr}}};
    SLL::printNode(n1);

    auto modifiedList = evenOdd(n1);

    SLL::printNode(modifiedList);

    cout << "-------------" << endl;

    SLL::printNode(n2);

    modifiedList = evenOdd(n2);

    SLL::printNode(modifiedList);

    cout << "-------------" << endl;

    SLL::printNode(n3);

    modifiedList = evenOdd(n3);

    SLL::printNode(modifiedList);

    cout << "-------------" << endl;
}