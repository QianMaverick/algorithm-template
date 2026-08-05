#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int v;
    int w;
    edge(int v,int w):v(v),w(w){}
};

void bfs(vector<vector<edge>> graph,vector<bool>& visit,int start,vector<int>& ans)
{
    queue<int> q;
    q.emplace(start);
    visit[start]=true;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        ans.emplace_back(cur);
        for(edge nex:graph[cur])
        {
            if(!visit[nex.v])
            {
                q.emplace(nex.v);
                visit[nex.v]=true;
            }
        }
    }
    return;
}

void dfs(vector<vector<edge>> graph,vector<bool>& visit,int start,vector<int>& ans)
{
    visit[start]=true;
    ans.emplace_back(start);
    for(edge nex:graph[start])
    {
        if(!visit[nex.v])
        {
            dfs(graph,visit,nex.v,ans);
        }
    }
    return;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<edge>> graph(n);
    vector<bool> visit(n,false);
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v,w);
        graph[v].emplace_back(u,w);
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