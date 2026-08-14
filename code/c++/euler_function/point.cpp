#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int num;
    cin >> num;
    int temp=num;
    map<int,int> nums;
    for(int i=2;i<=temp/i;++i)
    {
        while(temp%i==0)
        {
            ++nums[i];
            temp=temp/i;
        }
    }
    if(temp>1)
    {
        ++nums[temp];
    }
    int ans=num;
    for(pair<int,int> i:nums)
    {
        ans=ans*(i.first-1)/i.first;
    }
    cout << ans << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}