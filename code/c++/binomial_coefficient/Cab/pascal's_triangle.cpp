#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b;
    cin >> a >> b;
    int n=max(a,b);
    vector<vector<int>> nums(n+1,vector<int>(n+1,0));
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(j==0)
            {
                nums[i][j]=1;
            }
            else
            {
                nums[i][j]=nums[i-1][j-1]+nums[i-1][j];
            }
        }
    }
    cout << nums[a][b] << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}