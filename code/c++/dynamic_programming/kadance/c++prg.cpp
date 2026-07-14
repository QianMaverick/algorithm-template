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
    int ans=numeric_limits<int>::min()/2;
    vector<int> sums(nums);
    for(int i=0;i<n;++i)
    {
        ans=max(ans,sums[i]=max(nums[i],sums[i-1]+nums[i]));
    }
    cout << ans << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}