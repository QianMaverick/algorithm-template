#include <bits/stdc++.h>
using namespace std;

void prefix1()
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
    int l,r;
    cin >> l >> r;
    cout << sums[r]-sums[l-1] << endl;
    return;
}

void prefix2()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> nums(n+1,vector<int>(m+1,0));
    vector<vector<int>> sums(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> nums[i][j];
            sums[i][j]=nums[i][j]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
        }
    }
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << sums[x2][y2]-sums[x1-1][y2]-sums[x2][y1-1]+sums[x1-1][y1-1] << endl;
    return;
}

void difference1()
{
    int n;
    cin >> n;
    vector<int> sums(n+2,0);
    vector<int> nums(n+2,0);
    for(int i=1;i<=n;++i)
    {
        cin >> sums[i];
        nums[i]=sums[i]-sums[i-1];
    }
    int l,r,num;
    cin >> l >> r >> num;
    nums[l]=nums[l]+num;
    nums[r+1]=nums[r+1]-num;
    for(int i=1;i<=n;++i)
    {
        sums[i]=sums[i-1]+nums[i];
        cout << sums[i] << " ";
    }
    cout << endl;
    return;
}

void difference2()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> sums(n+2,vector<int>(m+2,0));
    vector<vector<int>> nums(n+2,vector<int>(m+2,0));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> sums[i][j];
            nums[i][j]=sums[i][j]-sums[i-1][j]-sums[i][j-1]+sums[i-1][j-1];
        }
    }
    int x1,y1,x2,y2,num;
    cin >> x1 >> y1 >> x2 >> y2 >> num;
    nums[x1][y1]=nums[x1][y1]+num;
    nums[x1][y2+1]=nums[x1][y2+1]-num;
    nums[x2+1][y1]=nums[x2+1][y1]-num;
    nums[x2+1][y2+1]=nums[x2+1][y2+1]+num;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            sums[i][j]=nums[i][j]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
            cout << sums[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void solve()
{
    prefix1();
    prefix2();
    difference1();
    difference2();
    return;
}

signed main()
{
    solve();
    return 0;
}