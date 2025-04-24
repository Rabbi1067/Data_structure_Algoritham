#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

Node *head = nullptr, *tail = nullptr;

// Function Prototypes
void insertEnd(int val);
void insertHead(int val);
void insertAtPosition(int pos, int val);
void deleteHead();
void deleteTail();
void deleteAtPosition(int pos);
void display();

int main() {
    int option;

    cout << "1.Insert\n2.Display\n3.Insert at Head\n4.Insert at Tail\n5.Insert at Pos\n6.Delete Head\n";
    cout << "7.Delete Tail\n8.Delete at Pos\n9.End\n";
    cout<<"Chooice One:"<<endl;

    while (cin >> option && option != 9) {
        if (option == 1) {
            int val;
            cout << "Insert value: ";
            cin >> val;
            insertEnd(val);
        } else if (option == 2) {
            display();
        } else if (option == 3) {
            int val;
            cout << "Insert at head: ";
            cin >> val;
            insertHead(val);
        } else if (option == 4) {
            int val;
            cout << "Insert at tail: ";
            cin >> val;
            insertEnd(val);
        } else if (option == 5) {
            int pos, val;
            cout << "Position: ";
            cin >> pos;
            cout << "Value: ";
            cin >> val;
            insertAtPosition(pos, val);
        } else if (option == 6) {
            deleteHead();
        } else if (option == 7) {
            deleteTail();
        } else if (option == 8) {
            int pos;
            cout << "Position to delete: ";
            cin >> pos;
            deleteAtPosition(pos);
        }
         else {
            cout << "Invalid option.\n";
        }
        cout << "Try Again: ";
    }
    return 0;
}

// Core Doubly Linked List Functions

void insertEnd(int val) {
    Node *newNode = new Node(val);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertHead(int val) {
    Node *newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtPosition(int pos, int val) {
    if (pos <= 1) {
        insertHead(val);
        return;
    }

    Node *cur = head;
    for (int i = 1; i < pos - 1 && cur; ++i) {
        cur = cur->next;
    }

    if (!cur || !cur->next) {
        insertEnd(val);
        return;
    }

    Node *newNode = new Node(val);
    newNode->next = cur->next;
    newNode->prev = cur;
    cur->next->prev = newNode;
    cur->next = newNode;
}

void deleteHead() {
    if (!head) return;
    Node *temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
}

void deleteTail() {
    if (!tail) return;
    Node *temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
}

void deleteAtPosition(int pos) {
    if (pos <= 1) {
        deleteHead();
        return;
    }

    Node *cur = head;
    for (int i = 1; i < pos && cur; ++i) {
        cur = cur->next;
    }

    if (!cur) return;

    if (cur->prev) cur->prev->next = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    if (cur == tail) tail = cur->prev;
    delete cur;
}

void display() {
    Node *cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}


