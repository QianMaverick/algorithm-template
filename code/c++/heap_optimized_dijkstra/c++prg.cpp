#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::max()/2;

class edge
{
public:
    int t;
    int w;
    edge(int t,int w):t(t),w(w){}
};

class compare
{
public:
    bool operator()(edge a,edge b)
    {
        return a.w>b.w;
    }
};

void dijkstra(vector<vector<edge>> graph,int start,vector<int>& dist)
{
    priority_queue<edge,vector<edge>,compare> pq;
    dist[start]=0;
    pq.emplace(start,0);
    while(!pq.empty())
    {
        edge cur=pq.top();
        pq.pop();
        if(cur.w<=dist[cur.t])
        {
            for(edge nex:graph[cur.t])
            {
                if(cur.w+nex.w<dist[nex.t])
                {
                    dist[nex.t]=cur.w+nex.w;
                    pq.emplace(nex.t,dist[nex.t]);
                }
            }
        }
    }
    return;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<edge>> graph(n);
    vector<int> dist(n,inf);
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v,w);
        graph[v].emplace_back(u,w);
    }
    int start;
    cin >> start;
    dijkstra(graph,start,dist);
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