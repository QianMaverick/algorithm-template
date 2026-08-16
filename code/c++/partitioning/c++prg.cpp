#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int sum=0;
    int l=1;
    while(l<=n)
    {
        int v=n/l;
        int r=n/v;
        sum=sum+(r-l+1)*v;
        l=r+1;
    }
    cout << sum << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}