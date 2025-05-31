#include<bits/stdc++.h>
using namespace std;
double k(vector<int>&value,vector<int>&weight,double cap)
{
    double mv=0;
    for(int i=value.size()-1;i>=0;i--)
    {
        if(cap>=weight[i])
        {
            cap=cap-weight[i];
            mv=mv+value[i];
        }
        else
        {
            mv=mv+(double (cap*value[i])/(weight[i]));
            break;
        }
    }
    return mv;
}
/*
120 100 60
30 20 10
*/
/*
100 150 200
20 30 50
*/
int main()
{
    int n;
        double cap;
    cin>>n>>cap;
    vector<int>value(n),weight(n);
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    cout<<fixed<<setprecision(2)<<k(value,weight,cap);
}


