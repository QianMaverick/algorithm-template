#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i=0;i<n;++i)
    {
        cin >> nums[i];
    }
    deque<int> dq;
    for(int i=0;i<n;++i)
    {
        while(!dq.empty()&&nums[dq.back()]>nums[i])
        {
            dq.pop_back();
        }
        dq.emplace_back(i);
        while(dq.front()<=i-m)
        {
            dq.pop_front();
        }
        if(-1<=i-m)
        {
            cout << nums[dq.front()] << " ";
        }
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}