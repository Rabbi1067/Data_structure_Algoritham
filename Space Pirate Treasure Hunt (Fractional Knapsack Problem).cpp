#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,w;
    cin>>n>>w;
    vector<double>value(n),weight(n);
    for(int i=0; i<n; i++)
    {
        cin>>value[i]>>weight[i];
    }
    vector<pair<double,double>>profit(n);
    for(int i=0; i<n; i++)
    {
        double x = value[i]/weight[i];
        profit[i].first = x;
        profit[i].second = weight[i];
    }
    sort(profit.rbegin(),profit.rend());
    int r = w;
    double totalsum=0.0;
    for(int i=0; i<n; i++)
    {
        int b = profit[i].second;
        if(b<=r)
        {
            totalsum+=b*profit[i].first;
            r-=b;
        }
        else
        {
            totalsum+=r*profit[i].first;
            break;
        }
    }
    //cout<<totalsum<<endl;
    cout << fixed << setprecision(1) << totalsum<< endl;
}
