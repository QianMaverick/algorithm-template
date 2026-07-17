#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,mod;
    cin >> n >> mod;
    vector<int> inves(n+1,0);
    inves[1]=1;
    for(int i=2;i<=n;++i)
    {
        inves[i]=(mod-mod/i)*inves[mod%i]%mod;
    }
    for(int i=1;i<=n;++i)
    {
        cout << inves[i] << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}