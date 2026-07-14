#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    vector<vector<int>> nums(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i]==b[j])
            {
                nums[i][j]=nums[i-1][j-1]+1;
            }
            else
            {
                nums[i][j]=max(nums[i-1][j],nums[i][j-1]);
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