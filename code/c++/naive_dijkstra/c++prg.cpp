#include <bits/stdc++.h>
using namespace std;

const int inf{numeric_limits<int>::max()/2};

void dijkstra(vector<vector<int>>& graph,vector<bool>& visited,int& start,vector<int>& dist)
{
    dist[start]=0;
    for(int i=0;i<graph.size();++i)
    {
        int cur{inf};
        for(int j=0;j<graph.size();++j)
        {
            if(!visited[j]&&(cur==inf||dist[j]<dist[cur]))
            {
                cur=j;
            }
        }
        visited[cur]=true;
        for(int i=0;i<graph.size();++i)
        {
            dist[i]=min(dist[i],dist[cur]+graph[cur][i]);
        }
    }
    return;
}

void solve()
{
    int nodes{},edges{},start{};
    cin >> nodes >> edges >> start;
    vector<vector<int>> graph(nodes,vector<int>(nodes,inf));
    vector<bool> visited(nodes,false);
    vector<int> dist(nodes,inf);
    for(int i=0;i<edges;++i)
    {
        int from{},to{},weight{};
        cin >> from >> to >> weight;
        graph[from][to]=weight;
        graph[to][from]=weight; //
    }
    dijkstra(graph,visited,start,dist);
    for(int& d:dist)
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