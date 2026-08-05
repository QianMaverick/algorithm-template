#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int m=n>>1;
    vector<vector<int>> st(m+1,vector<int>(n+1,0));
    for(int i=1;i<=n;++i)
    {
        cin >> st[0][i];
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j+(1<<i)-1<=n;++j)
        {
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    int l,r;
    cin >> l >> r;
    m=(r-l+1)>>1;
    cout << max(st[m][l],st[m][r-(1<<m)+1]) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}