#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1),w(n+1),s(n+1);
    for(int i=1;i<=n;++i)
    {
        cin >> v[i] >> w[i] >> s[i];
    }
    vector<vector<int>> nums(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            nums[i][j]=nums[i-1][j];
            for(int k=1;k<=s[i]&&j>=k*v[i];++k)
            {
                nums[i][j]=max(nums[i][j],nums[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout << nums[n][m] << endl;
    // vector<int> nums(m+1,0);
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=m;j>=v[i];--j)
    //     {
    //         for(int k=1;k<=s[i]&&j>=k*v[i];++k)
    //         {
    //             nums[j]=max(nums[j],nums[j-k*v[i]]+k*w[i]);
    //         }
    //     }
    // }
    // cout << nums[m] << endl;
    return;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(1,0),w(1,0);
    for(int i=1;i<=n;++i)
    {
        int a,b,s;
        cin >> a >> b >> s;
        int k=1;
        while(k<=s)
        {
            v.emplace_back(k*a);
            w.emplace_back(k*b);
            s=s-k;
            k=k*2;
        }
        if(s>0)
        {
            v.emplace_back(s*a);
            w.emplace_back(s*b);
        }
    }
    n=v.size()-1;
    vector<vector<int>> nums(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            nums[i][j]=nums[i-1][j];
            if(j>=v[i])
            {
                nums[i][j]=max(nums[i][j],nums[i-1][j-v[i]]+w[i]);
            }
        }
    }
    cout << nums[n][m] << endl;
    // n=v.size()-1;
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