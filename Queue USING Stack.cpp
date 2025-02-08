//Queue USING Stack

#include <bits/stdc++.h>
using namespace std;

struct mystack
{
    int top;
    int s_size;
    int *items;
};

mystack *createstack(int capacity)
{
    mystack *sq = new mystack();
    sq->top = -1;
    sq->s_size = capacity;
    sq->items = new int[capacity];
    return sq;
}
bool isEmpty(mystack* sq)
{
    return sq->top == -1;
}

bool isFull(mystack *sq)
{
    return sq->top==(sq->s_size-1);
}

void push(mystack *sq,int data)
{
    if (isFull(sq))
    {
        cout << "Stack is Full" << endl;
        return;
    }
    sq->top++;
    sq->items[sq->top] = data;
}
int pop(mystack* sq)
{

    if(isEmpty(sq))
    {
        cout<<"Stack is empty"<<endl;
        return -1;

    }
    return sq->items[sq->top--];
}

int peek(mystack * sq)
{
    if(isEmpty(sq))
    {
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    return sq->items[sq->top];
}

void enqueue(mystack *sq1,int data)
{
    if(isFull(sq1))
    {
        cout << "Queue is FULL" << endl;
    }
    else
    {
        push(sq1, data);
        cout << "Enqueued: " << data << endl;
    }
}

void dequeue(mystack *sq1,mystack *sq2)
{
    if (isEmpty(sq1) && isEmpty(sq2))
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    if(isEmpty(sq2))
    {
        while(!isEmpty(sq1))
        {
            int t=pop(sq1);
            push(sq2,t);
        }
    }
    cout << "Dequeued: " << pop(sq2) << endl;
}

void top(mystack *sq1,mystack *sq2)
{
    if (isEmpty(sq1) && isEmpty(sq2))
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    if(isEmpty(sq2))
    {
        while(!isEmpty(sq1))
        {
            int t=pop(sq1);
            push(sq2,t);
        }
    }
    cout << "Top Value is: " << peek(sq2) << endl;
}

int main()
{
    int capacity, choice, data;
    cout << "Enter Queue Capacity: ";
    cin >> capacity;

    mystack* sq1 = createstack(capacity);
    mystack* sq2 = createstack(capacity);

    while (true)
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Top Value\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to enqueue: ";
            cin >> data;
            enqueue(sq1, data);
            break;

        case 2:
            dequeue(sq1, sq2);
            break;

        case 3:
            top(sq1, sq2);
            break;

        case 4:
            cout << "END" << endl;

            return 0;

        default:
            cout << "Invalid Choice. Try again." << endl;
        }
    }
}

