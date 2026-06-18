#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::max()/2;

class edge
{
public:
    int v;
    int w;
};

class compare
{
public:
    bool operator()(edge a,edge b)
    {
        return a.w>b.w;
    }
};

int heap_optimized_prim(vector<vector<edge>> graph,int n)
{
    vector<int> dist(n,inf);
    vector<bool> visited(n,false);
    priority_queue<edge,vector<edge>,compare> pq;
    dist[0]=0;
    pq.emplace(0,0);
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
                if(!visited[nex.v]&&dist[nex.w]>nex.w)
                {
                    dist[nex.v]=nex.w;
                    pq.emplace(nex.v,nex.w);
                }
            }
        }
    }
    if(num==n)
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
    num=heap_optimized_prim(graph,n);
    cout << num << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}