#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n+1,vector<int>(1,0)),w(n+1,vector<int>(1,0));
    vector<int> s(n+1);
    for(int i=1;i<=n;++i)
    {
        cin >> s[i];
        for(int j=1;j<=s[i];++j)
        {
            int a,b;
            cin >> a >> b;
            v[i].emplace_back(a);
            w[i].emplace_back(b);
        }
    }
    vector<vector<int>> nums(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            nums[i][j]=nums[i-1][j];
            for(int k=1;k<=s[i];++k)
            {
                if(j>=v[i][k])
                {
                    nums[i][j]=max(nums[i][j],nums[i-1][j-v[i][k]]+w[i][k]);
                }
            }
        }
    }
    cout << nums[n][m] << endl;
// 	vector<int> nums(m+1,0);
// 	for(int i=1;i<=n;++i)
// 	{
// 		for(int j=m;j>=1;--j)
// 		{
// 			for(int k=1;k<=s[i];++k)
// 			{
// 				if(j>=v[i][k])
// 				{
// 					nums[j]=max(nums[j],nums[j-v[i][k]]+w[i][k]);
// 				}
// 			}
// 		}
// 	}
// 	cout << nums[m] << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}