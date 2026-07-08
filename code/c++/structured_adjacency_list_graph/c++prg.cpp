#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int v;
    int w;
    edge(int v,int w):v(v),w(w){}
};

void bfs(vector<vector<edge>> graph,vector<bool>& visited,int start,vector<int>& ans)
{
    queue<int> q;
    q.emplace(start);
    visited[start]=true;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        ans.emplace_back(cur);
        for(edge nex:graph[cur])
        {
            if(!visited[nex.v])
            {
                q.emplace(nex.v);
                visited[nex.v]=true;
            }
        }
    }
    return;
}

void dfs(vector<vector<edge>> graph,vector<bool>& visited,int start,vector<int>& ans)
{
    visited[start]=true;
    ans.emplace_back(start);
    for(edge nex:graph[start])
    {
        if(!visited[nex.v])
        {
            dfs(graph,visited,nex.v,ans);
        }
    }
    return;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<edge>> graph(n);
    vector<bool> visited(n,false);
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v,w);
        graph[v].emplace_back(u,w);
    }
    int start=0;
    vector<int> ans;
    bfs(graph,visited,start,ans);
    dfs(graph,visited,start,ans);
    for(int i=0;i<ans.size();++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}