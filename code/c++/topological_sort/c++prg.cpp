#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> in(n,0);
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        ++in[v];
    }
    queue<int> q;
    for(int i=0;i<n;++i)
    {
        if(in[i]==0)
        {
            q.emplace(i);
        }
    }
    vector<int> ans;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        ans.emplace_back(cur);
        for(int nex:graph[cur])
        {
            --in[nex];
            if(in[nex]==0)
            {
                q.emplace(nex);
            }
        }
    }
    if(ans.size()==n)
    {
        for(int i:ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << -1 << endl;
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}