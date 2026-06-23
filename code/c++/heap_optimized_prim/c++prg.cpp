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

struct compare
{
public:
    bool operator()(edge a,edge b)
    {
        return a.w>b.w;
    }
};

int heap_optimized_prim(vector<vector<edge>> graph)
{
    priority_queue<edge,vector<edge>,compare> pq;
    vector<bool> visited(graph.size(),false);
    vector<int> dist(graph.size(),inf);
    pq.emplace(0,0);
    dist[0]=0;
    int sum=0;
    int num=0;
    while(!pq.empty())
    {
        edge cur=pq.top();
        pq.pop();
        if(!visited[cur.v])
        {
            visited[cur.v]=true;
            sum=sum+cur.w;
            ++num;
            for(edge nex:graph[cur.v])
            {
                if(!visited[nex.v]&&dist[nex.v]>nex.w)
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
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v,w);
        graph[v].emplace_back(u,w);
    }
    int num;
    num=heap_optimized_prim(graph);
    cout << num << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}