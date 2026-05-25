#include <bits/stdc++.h>
using namespace std;

const int inf{numeric_limits<int>::max()/2};

void bfs(vector<vector<int>> graph,vector<bool>& visited,int start,vector<int>& ans)
{
    queue<int> q{};
    q.emplace(start);
    visited[start]=true;
    while(!q.empty())
    {
        int cur{q.front()};
        q.pop();
        ans.emplace_back(cur);
        for(int i=0;i<graph[cur].size();++i)
        {
            if(!visited[i]&&graph[cur][i]!=inf)
            {
                q.emplace(i);
                visited[i]=true;
            }
        }
    }
    return;
}

void bfsall(vector<vector<int>> graph,vector<bool>& visited,vector<int>& ans)
{
    for(int i=0;i<graph.size();++i)
    {
        if(!visited[i])
        {
            bfs(graph,visited,i,ans);
        }
    }
    return;
}

void dfs(vector<vector<int>> graph,vector<bool>& visited,int start,vector<int>& ans)
{
    ans.emplace_back(start);
    visited[start]=true;
    for(int i=0;i<graph[start].size();++i)
    {
        if(!visited[i]&&graph[start][i]!=inf)
        {
            dfs(graph,visited,i,ans);
        }
    }
    return;
}

void dfsall(vector<vector<int>> graph,vector<bool>& visited,vector<int>& ans)
{
    for(int i=0;i<graph.size();++i)
    {
        if(!visited[i])
        {
            dfs(graph,visited,i,ans);
        }
    }
    return;
}

void solve()
{
    int nodes{},edges{};
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes,vector<int>(nodes,inf));
    vector<bool> visited(nodes,false);
    vector<int> ans{};
    int start{0};
    for(int i=0;i<edges;++i)
    {
        int from{},to{},weight{};
        cin >> from >> to >> weight; //
        graph[from][to]=weight;
        graph[to][from]=weight; //
    }
    bfs(graph,visited,start,ans);
    // bfsall(graph,visited,ans);
    // dfs(graph,visited,start,ans);
    // dfsall(graph,visited,ans);
    for(int a:ans)
    {
        cout << a << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}