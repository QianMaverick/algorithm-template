#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1),w(n+1);
    for(int i=1;i<=n;++i)
    {
        cin >> v[i] >> w[i];
    }
    vector<vector<int>> nums(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            nums[i][j]=nums[i-1][j];
            if(j>=v[i])
            {
                nums[i][j]=max(nums[i][j],nums[i-1][j-v[i]]+w[i]);
            }
        }
    }
    cout << nums[n][m] << endl;
    // vector<int> nums(m+1,0);
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=m;j>=v[i];--j)
    //     {
    //         nums[j]=max(nums[j],nums[j-v[i]]+w[i]);
    //     }
    // }
    // cout << nums[m] << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}