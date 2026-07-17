#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if(n==0)
    {
        cout << 1 << endl;
        return;
    }
    int num=1;
    for(int i=1;i<=n;++i)
    {
        num=num*(4*i-2)/(i+1);
    }
    cout << num << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}