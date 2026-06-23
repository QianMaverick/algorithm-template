#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::max()/2;

void dijkstra(vector<vector<int>> graph,vector<bool> visited,int start,vector<int>& dist)
{
    dist[start]=0;
    for(int i=0;i<graph.size();++i)
    {
        int cur=inf;
        for(int j=0;j<graph.size();++j)
        {
            if(!visited[j]&&(cur==inf||dist[j]<dist[cur]))
            {
                cur=j;
            }
        }
        visited[cur]=true;
        for(int j=0;j<graph.size();++j)
        {
            dist[j]=min(dist[j],dist[cur]+graph[cur][j]);
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
    vector<int> dist(n,inf);
    dijkstra(graph,visited,start,dist);
    for(int i:dist)
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