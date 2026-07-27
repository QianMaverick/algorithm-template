#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::max()/2;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n+1,0);
    vector<int> sums(n+1,0);
    for(int i=1;i<=n;++i)
    {
        cin >> nums[i];
        sums[i]=sums[i-1]+nums[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,inf));
    for(int i=1;i<=n;++i)
    {
        dp[i][i]=0;
    }
    for(int i=2;i<=n;++i)
    {
        for(int l=1;l+i-1<=n;++l)
        {
            int r=l+i-1;
            for(int j=l;j<r;++j)
            {
                dp[l][r]=min(dp[l][r],dp[l][j]+dp[j+1][r]);
            }
            dp[l][r]=dp[l][r]+sums[r]-sums[l-1];
        }
    }
    cout << dp[1][n] << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}