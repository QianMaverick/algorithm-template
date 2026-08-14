#include <bits/stdc++.h>
using namespace std;

void sovle()
{
    int n;
    cin >> n;
    vector<int> ans(n+1,0);
    ans[1]=1;
    vector<bool> nums(n+1,true);
    vector<int> temp;
    nums[0]=false;
    nums[1]=false;
    for(int i=2;i<=n;++i)
    {
        if(nums[i])
        {
            temp.emplace_back(i);
            ans[i]=i-1;
        }
        for(int j:temp)
        {
            if(i*j>n)
            {
                break;
            }
            nums[i*j]=false;
            if(i%j==0)
            {
                ans[i*j]=ans[i]*j;
                break;
            }
            else
            {
                ans[i*j]=ans[i]*(j-1);
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    sovle();
    return 0;
}