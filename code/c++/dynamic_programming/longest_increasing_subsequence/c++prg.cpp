#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int& i:nums)
    {
        cin >> i;
    }
    int ans=0;
    vector<int> lens(n,1);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(nums[j]<nums[i])
            {
                ans=max(ans,lens[i]=max(lens[i],lens[j]+1));
            }
        }
    }
    cout << ans << endl;
    return;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int& i:nums)
    {
        cin >> i;
    }
    int ans=0;
    vector<int> lens;
    for(int i:nums)
    {
        auto it=lower_bound(lens.begin(),lens.end(),i);
        if(it!=lens.end())
        {
            *it=i;
        }
        else
        {
            lens.emplace_back(i);
        }
    }
    cout << lens.size() << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}