#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> point(n);
    for(pair<int,int>& i:point)
    {
        cin >> i.first >> i.second;
    }
    vector<int> sits;
    for(pair<int,int> i:point)
    {
        sits.emplace_back(i.first);
    }
    vector<pair<int,int>> asks(m);
    for(pair<int,int>& i:asks)
    {
        cin >> i.first >> i.second;
        sits.emplace_back(i.first);
        sits.emplace_back(i.second);
    }
    sort(sits.begin(),sits.end(),less<int>());
    sits.erase(unique(sits.begin(),sits.end()),sits.end());
    int sz=sits.size();
    vector<int> vals(sz,0);
    for(pair<int,int> i:point)
    {
        int j=lower_bound(sits.begin(),sits.end(),i.first)-sits.begin();
        vals[j]+=i.second;
    }
    vector<int> sums(sz+1,0);
    for(int i=1;i<=sz;++i)
    {
        sums[i]=sums[i-1]+vals[i-1];
    }
    for(pair<int,int> i:asks)
    {
        int a=lower_bound(sits.begin(),sits.end(),i.first)-sits.begin();
        int b=lower_bound(sits.begin(),sits.end(),i.second)-sits.begin();
        cout << sums[b+1]-sums[a] << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}