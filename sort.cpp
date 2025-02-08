/*2. Sort the array in descending order.
(Take the last digit of your student id and mod it by
 2. if the result=0, use Selection Sort ; if the result=1, use Bubble Sort ;
  Otherwise, use Insertion Sort)
*/

#include<bits/stdc++.h>
using namespace std;
void dselection(int ary[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int maxindex=i;
        for(int j=i+1; j<n; j++)
        {
            if(ary[maxindex]<ary[j])
            {
                maxindex=j;
            }
        }
        swap(ary[i],ary[maxindex]);
    }
    cout<<"After sorting the array in descending order with Selection Sort: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<ary[i]<<" ";
    }
    cout<<endl;
}

void dbubble(int ary[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(ary[j]<ary[j+1])
            {
                swap(ary[j],ary[j+1]);
            }
        }
    }
    cout<<"After sorting the array in descending order with Bubble Sort: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<ary[i]<<" ";
    }
    cout<<endl;
}

void dinsersion(int ary[],int n)
{
    for(int i=1; i<n; i++)
    {
        int key=ary[i];
        int j=i-1;
        while(ary[j]<key and j>=0)
        {
            ary[j+1]=ary[j];
            j--;
        }
        ary[j+1]=key;
    }
    cout<<"After sorting the array in descending order with Insertion Sort: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<ary[i]<<" ";
    }
    cout<<endl;
}



int main()
{
    cout<<"Enter the size of array: ";
    int n;
    cin>>n;
    int ary[n];
    cout<<"Enter "<<n<<" numbers:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<"-no. index is: ";
        cin>>ary[i];
    }
    cout<<"Entered array is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<ary[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter the last digit of your student id: ";
    int id;
    cin>>id;
    if(id%3==0)
    {
        dselection(ary,n);
    }
    else if(id%2==1)
    {
        dbubble(ary,n);
    }
    else
    {
        dinsersion(ary,n);
    }
}


