#include <bits/stdc++.h>
using namespace std;

const int inf{numeric_limits<int>::max()/2};

struct edge
{
    int to{};
    int weight{};
    edge():to(0),weight(0){}
    edge(int t):to(t),weight(0){}
    edge(int t,int w):to(t),weight(w){}
};

struct compare
{
    bool operator()(edge a,edge b)
    {
        return a.weight>b.weight;
    }
};

void dijkstra(vector<vector<edge>> graph,int start,vector<int>& dist)
{
    priority_queue<edge,vector<edge>,compare> pq{};
    dist[start]=0;
    pq.emplace(start,0);
    while(!pq.empty())
    {
        edge cur{pq.top()};
        pq.pop();
        if(cur.weight<=dist[cur.to])
        {
            for(edge edge:graph[cur.to])
            {
                if(cur.weight+edge.weight<dist[edge.to])
                {
                    dist[edge.to]=cur.weight+edge.weight;
                    pq.emplace(edge.to,dist[edge.to]);
                }
            }
        }
    }
    return;
}

void solve()
{
    int nodes{},edges{},start{};
    cin >> nodes >> edges >> start;
    vector<vector<edge>> graph(nodes,vector<edge>{});
    vector<int> dist(nodes,inf);
    for(int i=0;i<edges;++i)
    {
        int from{},to{},weight{};
        cin >> from >> to >> weight;
        graph[from].emplace_back(to,weight);
        graph[to].emplace_back(from,weight); //
    }
    dijkstra(graph,start,dist);
    for(int d:dist)
    {
        cout << d << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}