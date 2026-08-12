#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string str;
    cin >> str;
    int n=str.size();
    vector<vector<bool>> nums(n,vector<bool>(n,false));
    for(int i=0;i<n;++i)
    {
        nums[i][i]=true;
    }
    int a=0,b=1;
    for(int l=2;l<=n;++l)
    {
        for(int i=0;i<n;++i)
        {
            int j=l+i-1;
            if(j>=n)
            {
                break;
            }
            if(str[i]==str[j])
            {
                if(j-i<3)
                {
                    nums[i][j]=true;
                }
                else
                {
                    nums[i][j]=nums[i+1][j-1];
                }
            }
            if(nums[i][j]&&l>b)
            {
                a=i;
                b=l;
            }
        }
    }
    cout << str.substr(a,b) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}