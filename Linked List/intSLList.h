#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode
{
public:
    int data;
    IntSLLNode *next;

    IntSLLNode()
    {
        next = 0;
    }
    IntSLLNode(int _data, IntSLLNode *ptr = 0)
    {
        data = _data;
        next = ptr;
    }
};

class IntSLList
{
public:
    IntSLList()
    {
        head = tail = 0;
    }
    ~IntSLList();
    int isEmpty(){
        return head == 0;
    }
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead(); //delete the head and return its data;
    int deleteFromTail(); //delete the tail and return its data;
    void deleteNode(int);
    bool isInList(int) const;

private:
    IntSLLNode *head, *tail;

};

#endif