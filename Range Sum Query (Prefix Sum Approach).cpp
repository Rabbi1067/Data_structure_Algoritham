//Range Sum Query (Prefix Sum Approach)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Input your array size: ";
    cin >> n;
    vector<int> a(n), prefix(n + 1, 0);

    cout << "Input array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    while(q--)
    {
        int l, r;
        cout << "Enter range (0-based l r): ";
        cin >> l >> r;
        cout << "Sum from " << l << " to " << r << " = " << prefix[r + 1] - prefix[l] << endl;
    }

    return 0;
}
/*
5
1 2 3 4 5
3
1 3
0 4
2 2 
*/
