#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::max()/2;

void bfs(vector<vector<int>> graph,vector<bool>& visited,int start,vector<int>& ans)
{
    queue<int> q;
    q.emplace(start);
    visited[start]=true;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        ans.emplace_back(cur);
        for(int i=0;i<graph[cur].size();++i)
        {
            if(!visited[i]&&graph[cur][i]!=inf)
            {
                q.emplace(i);
                visited[i]=true;
            }
        }
    }
    return;
}

void dfs(vector<vector<int>> graph,vector<bool>& visited,int start,vector<int>& ans)
{
    ans.emplace_back(start);
    visited[start]=true;
    for(int i=0;i<graph[start].size();++i)
    {
        if(!visited[i]&&graph[start][i]!=inf)
        {
            dfs(graph,visited,i,ans);
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
        cin >> u >> v >> w; //
        graph[u][v]=w;
        graph[v][u]=w; //
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