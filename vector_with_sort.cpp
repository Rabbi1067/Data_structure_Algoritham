#include <bits/stdc++.h>
using namespace std;

void dselection(vector<int>& ary)
{
    int n = ary.size();
    for (int i = 0; i < n - 1; i++)
    {
        int maxindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ary[maxindex] < ary[j]) //use ">" to ascending order
            {
                maxindex = j;
            }
        }
        swap(ary[i], ary[maxindex]);
    }
    cout << "After sorting the array in descending order with Selection Sort:\n";
    for (int num : ary)
    {
        cout << num << " ";
    }
    cout << endl;
}

void dbubble(vector<int>& ary)
{
    int n = ary.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ary[j] < ary[j + 1]) //use ">" to ascending order
            {
                swap(ary[j], ary[j + 1]);
            }
        }
    }
    cout << "After sorting the array in descending order with Bubble Sort:\n";
    for (int num : ary)
    {
        cout << num << " ";
    }
    cout << endl;
}

void dinsertion(vector<int>& ary)
{
    int n = ary.size();
    for (int i = 1; i < n; i++)
    {
        int key = ary[i];
        int j = i - 1;
        while (j >= 0 && ary[j] < key) //use ">" to ascending order
        {
            ary[j + 1] = ary[j];
            j--;
        }
        ary[j + 1] = key;
    }
    cout << "After sorting the array in descending order with Insertion Sort:\n";
    for (int num : ary)
    {
        cout << num << " ";
    }
    cout << endl;
}

void insertAtPosition(vector<int>& ary, int value, int pos)
{
    if (pos >= 0 && pos <= ary.size())
    {
        ary.insert(ary.begin() + pos, value);
    }
    else
    {
        cout << "Invalid position!" << endl;
    }
}

void removeElement(vector<int>& ary, int pos)
{
    if (pos >= 0 && pos < ary.size())
    {
        ary.erase(ary.begin() + pos);
    }
    else
    {
        cout << "Invalid position!" << endl;
    }
}


int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> ary(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ary[i];
    }

    vector<int> selectionVec = ary, bubbleVec = ary, insertionVec = ary;

    int id;
    cout<<"Enter your ID: ";
    cin>>id;
    if(id%3==0)
    {
        dselection(ary);
    }
    else if(id%3==1)
    {
        dbubble(ary);
    }
    else
    {
        dinsertion(ary);
    }

    int choice;
    cout << "Do you want to insert (1) or remove (2) an element? ";
    cin >> choice;
    if (choice == 1)
    {
        int value, pos;
        cout << "Enter value to insert: ";
        cin >> value;
        cout << "Enter position to insert at (0-based index): ";
        cin >> pos;
        insertAtPosition(ary, value, pos);
    }
    else if (choice == 2)
    {
        int pos;
        cout << "Enter position to remove (0-based index): ";
        cin >> pos;
        removeElement(ary, pos);
    }

    cout << "Array after operation: ";
    for (int num : ary)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

