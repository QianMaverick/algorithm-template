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
        int u=q.front();
        q.pop();
        ans.emplace_back(u);
        for(int v:graph[u])
        {
            --in[v];
            if(in[v]==0)
            {
                q.emplace(v);
            }
        }
    }
    if(ans.size()==n)
    {
        for(int a:ans)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return;
}

signed main()
{
    solve();
    return 0;
}