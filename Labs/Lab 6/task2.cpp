#include <iostream>
using namespace std;
int front = -1;
int rear = -1;
int N = 8;
int arr[8];
bool isFull()
{
    if (rear == N - 1) // Rear has reached the last position in the array
        return true;
    else
        return false;
}
bool isEmpty()
{
    if (front == -1 || front > rear) // Front has moved beyond rear
        return true;
    else
        return false;
}
void enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue is Full!" << endl;
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = value;
}
void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    else if (front == rear)
    { // Only one element left

        front = rear = -1;
    }
    else
    {
        front++;
    }
}
void display()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "\nElements of the Queue: \n"
         << endl;
    for (int i = front; i <= rear; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}
int main()
{
    enqueue(1);
    enqueue(3);
    enqueue(7);
    enqueue(4);
    enqueue(1);
    enqueue(6);
    enqueue(8);
    enqueue(10);
    display();
    dequeue(); // Remove first element (1)
    dequeue(); // Remove next element (3)
    display();
    return 0;
}