#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::max()/2;

class edge
{
public:
    int v;
    int w;
    edge(int v,int w):v(v),w(w){}
};

class compare
{
public:
    bool operator()(edge a,edge b)
    {
        return a.w>b.w;
    }
};

int heap_optimized_prim(vector<vector<edge>> graph,vector<bool>& visit,vector<int>& dist)
{
    priority_queue<edge,vector<edge>,compare> pq;
    pq.emplace(0,0);
    dist[0]=0;
    int sum=0;
    int num=0;
    while(!pq.empty())
    {
        edge cur=pq.top();
        pq.pop();
        if(!visit[cur.v])
        {
            visit[cur.v]=true;
            sum=sum+cur.w;
            ++num;
            for(edge nex:graph[cur.v])
            {
                if(!visit[nex.v]&&dist[nex.v]>nex.w)
                {
                    dist[nex.v]=nex.w;
                    pq.emplace(nex.v,nex.w);
                }
            }
        }
    }
    if(num==graph.size())
    {
        return sum;
    }
    else
    {
        return inf;
    }
    return 0;
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
    vector<int> dist(n,inf);
    cout << heap_optimized_prim(graph,visit,dist) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}