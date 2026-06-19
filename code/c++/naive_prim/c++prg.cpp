#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::max()/2;

int naive_prim(vector<vector<int>> graph,int n)
{
    vector<int> dist(n,inf);
    vector<bool> visited(n,false);
    dist[0]=0;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        int cur=-1;
        for(int j=0;j<n;++j)
        {
            if(!visited[j]&&(cur==-1||dist[cur]>dist[j]))
            {
                cur=j;
            }
        }
        if(dist[cur]!=inf)
        {
            visited[cur]=true;
            sum=sum+dist[cur];
            for(int l=0;l<n;++l)
            {
                if(!visited[l])
                {
                    dist[l]=min(dist[l],graph[cur][l]);
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
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u][v]=min(graph[u][v],w);
        graph[v][u]=min(graph[v][u],w);
    }
    int num;
    num=naive_prim(graph,n);
    cout << num << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}