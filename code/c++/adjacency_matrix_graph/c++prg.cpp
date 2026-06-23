#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::max()/2;

void bfs(vector<vector<int>> graph,vector<bool> visited,int start,vector<int>& ans)
{
    queue<int> q;
    q.emplace(start);
    visited[start]=true;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        ans.emplace_back(cur);
        for(int nex:graph[cur])
        {
            if(!visited[nex]&&graph[cur][nex]!=inf)
            {
                q.emplace(nex);
                visited[nex]=true;
            }
        }
    }
    return;
}

void dfs(vector<vector<int>> graph,vector<bool> visited,int start,vector<int>& ans)
{
    visited[start]=true;
    ans.emplace_back(start);
    for(int nex:graph[start])
    {
        if(!visited[nex]&&graph[start][nex]!=inf)
        {
            dfs(graph,visited,nex,ans);
        }
    }
    return;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n,vector<int>(n,inf));
    vector<bool> visited(n,false);
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u][v]=w;
        graph[v][u]=w;
    }
    int start=0;
    vector<int> ans;
    bfs(graph,visited,start,ans);
    dfs(graph,visited,start,ans);
    for(int i:ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}