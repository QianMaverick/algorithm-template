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
    int ans=nums[0];
    int sum=nums[0];
    for(int i=1;i<n;++i)
    {
        ans=max(ans,sum=max(sum+nums[i],nums[i]));
    }
    cout << ans << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}