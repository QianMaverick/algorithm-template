#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::max()/2;

void bfs(vector<vector<int>> graph,vector<bool>& visit,int start,vector<int>& ans)
{
    queue<int> q;
    q.emplace(start);
    visit[start]=true;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        ans.emplace_back(cur);
        for(int nex=0;nex<graph[cur].size();++nex)
        {
            if(!visit[nex]&&graph[cur][nex]!=inf)
            {
                q.emplace(nex);
                visit[nex]=true;
            }
        }
    }
    return;
}

void dfs(vector<vector<int>> graph,vector<bool>& visit,int start,vector<int>& ans)
{
    visit[start]=true;
    ans.emplace_back(start);
    for(int nex=0;nex<graph[start].size();++nex)
    {
        if(!visit[nex]&&graph[start][nex]!=inf)
        {
            dfs(graph,visit,nex,ans);
        }
    }
    return;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n,vector<int>(n,inf));
    vector<bool> visit(n,false);
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u][v]=w;
        graph[v][u]=w;
    }
    int start;
    cin >> start;
    vector<int> ans;
    bfs(graph,visit,start,ans);
    dfs(graph,visit,start,ans);
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