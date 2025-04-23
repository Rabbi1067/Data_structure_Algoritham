//Creating a Node in Doubly Linked List


//The structure of a Node:

struct Node{
int data;
Node * next;
Node * prev;
};

/*Allocating a memory space for a node:
Node * head = (Node*)(malloc(sizeof(Node)));
head = NULL;*/

//Insertion at Head

Node * insertAtHead(Node * head, int data)

{

    Node * temp = (Node*)(malloc(sizeof(Node)));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL)
        return temp;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;

}

//Insertion at Tail

Node * insertAtTail(Node * head, int data)

{

    Node * temp = (Node*)(malloc(sizeof(Node)));
    Node * cur = (Node*)(malloc(sizeof(Node)));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL) return temp;
    cur = head;
    while(cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;

}


//Insertion at any other position

Node * insertMiddle(Node * head, int data, int key)

{

// insert the new node after the node containing key
    Node * temp = (Node*)(malloc(sizeof(Node)));
    Node * cur = (Node*)(malloc(sizeof(Node)));
    temp->data = data;
    cur = head;
    while(1)
    {

        if(cur->data == key) break;
        cur=cur->next;

    }

    temp->next = cur->next;
    temp->prev = cur;
    cur->next->prev = temp;
    cur->next = temp;
    return head;

}

//Delete at Head

Node * deleteAtHead(Node * head)

{

    Node * cur = (Node*)(malloc(sizeof(Node)));

    cur = head;

    if(head==NULL)

        return NULL;

    head = head->next;

    if(head!=NULL)

        head->prev = NULL;

    delete(cur);

    return head;

}

//Delete at Tail

Node * deleteAtTail(Node * head)

{

    Node * cur = (Node*)(malloc(sizeof(Node)));

    cur = head;

    if(cur == NULL) return NULL;

    if(cur->next == NULL)
    {

        delete(cur);

        return NULL;

    }

    while(cur->next->next != NULL)
    {

        cur = cur->next;
    }

    delete(cur->next);

    cur->next = NULL;

    return head;

}

//Delete at any other position

Node * deleteMiddle(Node * head, int key)

{

// delete the node containing key

    Node * cur = (Node*)(malloc(sizeof(Node)));

    cur = head;

    while(1)

    {

        if(cur->data == key)

            break;

        cur=cur->next;

    }

    cur->next->prev = cur->prev;

    cur->prev->next = cur->next;

    delete(cur);

    return head;

}

