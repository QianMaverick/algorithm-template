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
    priority_queue<int,vector<int>,less<int>> maxq;
    priority_queue<int,vector<int>,greater<int>> minq;
    for(int i:nums)
    {
        if(maxq.empty()||maxq.top()>=i)
        {
            maxq.emplace(i);
        }
        else
        {
            minq.emplace(i);
        }
        if(maxq.size()>minq.size()+1)
        {
            minq.emplace(maxq.top());
            maxq.pop();
        }
        else if(minq.size()>maxq.size())
        {
            maxq.emplace(minq.top());
            minq.pop();
        }
        if(i%2==0)
        {
            cout << maxq.top() << " ";
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