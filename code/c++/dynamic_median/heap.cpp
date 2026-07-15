#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    priority_queue<int,vector<int>,less<int>> maxq;
    priority_queue<int,vector<int>,greater<int>> minq;
    for(int i=0;i<n;++i)
    {
        int temp;
        cin >> temp;
        if(maxq.empty()||maxq.top()>=temp)
        {
            maxq.emplace(temp);
        }
        else
        {
            minq.emplace(temp);
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
            cout << maxq.top() << endl;
        }
    }
    return;
}

signed main()
{
    solve();
    return 0;
}