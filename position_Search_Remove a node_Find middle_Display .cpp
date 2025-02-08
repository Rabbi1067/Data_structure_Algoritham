#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
}*head,*tail;

void insert_head(int n)
{
    Node *temp=new Node();
    temp->data=n;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {

        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}


void insert_tail(int n)
{
    Node * temp =new Node();
    Node * cur =head;
    temp->data=n;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=temp;
        temp->prev=cur;
    }
}

int countnode()
{
    Node *cur=head;
    int count=0;
    while(cur!=NULL)
    {
        cur=cur->next;
        count++;
    }
    return count;
}

void insert_position(int k, int n)
{
    if(k==1)
    {
        insert_head(n);
    }
    else if(k==(countnode()+1))
    {
        insert_tail(n);
    }
    else if(k<=countnode())
    {
        Node *cur=head;
        for(int i=1;i<k-1;i++)
        {
            cur=cur->next;
        }
        Node *temp=new Node();
        temp->data=n;
        temp->next=cur->next;
        temp->prev=cur;
        cur->next->prev=temp;
        cur->next=temp;
    }
    else
    {
        if(head==NULL)
        {
            insert_head(n);
        }
        else
        {
            cout<<"This position is not exist in this linked list"<<endl;
        }
    }
}

void search(int key)
{
    int x=countnode();
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout<<"Found"<<endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found" << endl;
}
void remove(int key)
{

    Node *cur=head;
    while(cur!=NULL && cur->data!=key)
    {
        cur=cur->next;
    }


    if (!cur)
    {
        cout << "Value " << key << " not found in the list.\n";
        return;
    }
    else
    {
        if(cur==head)
        {
            head=head->next;
            head->prev=NULL;
        }
        else if(cur->next==NULL)
        {
            Node *cur=head;
            while(cur->next->next!=NULL)
            {
                cur=cur->next;
            }
            cur->next=NULL;
            tail=cur;
        }
        else
        {
            cur->next->prev=cur->prev;
            cur->prev->next=cur->next;
        }
    }
}

void middle()
{
    Node *cur=head;
    int count=0;
    while(cur!=NULL)
    {
        cur=cur->next;
        count++;
    }
    if (count == 0) {
        cout << "List is empty." << endl;
        return;
    }
    int middle;
    if(count%2==0)
    {
        middle=count/2;
    }
    else
    {
        middle=(count/2)+1;
    }
    cur=head;
    for(int i=1; i<middle-1; i++)
    {
        cur=cur->next;
    }
    cout<<"Middle node Index is- "<<middle<<" and Middle value is- "<<cur->next->data<<endl;
}


void display()
{
    Node *cur=head;
    cout<<"Your Linked List is: ";
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<endl;
}


int main()
{
    head=NULL;
    tail=NULL;
    cout<<"Please Choose:"<<endl;
    cout << "1. Insert at position" << endl;
    cout << "2. Search a node" << endl;
    cout << "3. Remove a node" << endl;
    cout << "4. Find middle node" << endl;
    cout << "5. Display" << endl;
    cout << "6. END the program" << endl;
    int i;
    cin>>i;
    while(i<=5)
    {
        if(i==1)
        {
            cout<<"Position: ";
            int k;
            cin>>k;
            cout<<"New Insert Value: ";
            int n;
            cin>>n;
            insert_position(k,n);
        }
        else if(i==2)
        {
            cout<<"Input Search KEY Value: ";
            int key;
            cin>>key;
            search(key);
        }
        else if(i==3)
        {
            cout<<"Input Remove KEY Value: ";
            int key;
            cin>>key;
            remove(key);
        }
        else if(i==4)
        {
            middle();
        }
        else
        {
            display();
        }
        cout<<"Please Choose Again:"<<endl;
        cout << "1. Insert at position" << endl;
        cout << "2. Search a node" << endl;
        cout << "3. Remove a node" << endl;
        cout << "4. Find middle node" << endl;
        cout << "5. Display" << endl;
        cout << "6. END the program" << endl;
        cin>>i;
    }
}

