#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n{};
    cin >> n;
    int m{(int)(log2(n))};
    int st[m+1][n+1]{};
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
    int l{},r{};
    cin >> l >> r;
    m=(int)(log2(r-l+1));
    cout << max(st[m][l],st[m][r-(1<<m)+1]) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}