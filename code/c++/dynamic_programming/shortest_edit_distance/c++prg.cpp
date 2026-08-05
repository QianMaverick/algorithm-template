#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    for(int i=1;i<=m;++i)
    {
        cin >> b[i];
    }
    vector<vector<int>> nums(n+1,vector<int>(m+1));
    for(int i=0;i<=n;++i)
    {
        nums[i][0]=i;
    }
    for(int j=0;j<=m;++j)
    {
        nums[0][j]=j;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])
            {
                nums[i][j]=nums[i-1][j-1];
            }
            else
            {
                nums[i][j]=min({nums[i-1][j],nums[i][j-1],nums[i-1][j-1]})+1;
            }
        }
    }
    cout << nums[n][m] << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}