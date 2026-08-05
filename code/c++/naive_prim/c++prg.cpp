#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::max()/2;

int naive_prim(vector<vector<int>> graph,vector<bool>& visit,vector<int>& dist)
{
    int n=graph.size();
    dist[0]=0;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        int cur=-1;
        for(int j=0;j<n;++j)
        {
            if(!visit[j]&&(cur==-1||dist[cur]>dist[j]))
            {
                cur=j;
            }
        }
        if(dist[cur]!=inf)
        {
            visit[cur]=true;
            sum=sum+dist[cur];
            for(int j=0;j<n;++j)
            {
                if(!visit[j])
                {
                    dist[j]=min(dist[j],graph[cur][j]);
                }
            }
        }
        else
        {
            return inf;
        }
    }
    return sum;
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
    vector<int> dist(n,inf);
    cout << naive_prim(graph,visit,dist) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}