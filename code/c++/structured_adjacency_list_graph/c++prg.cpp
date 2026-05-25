#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int to{};
    int weight{};
    edge():to(0),weight(0){}
    edge(int& t):to(t),weight(){}
    edge(int& t,int& w):to(t),weight(w){}
};

void bfs(vector<vector<edge>>& graph,vector<bool>& visited,int& start,vector<int>& ans)
{
    queue<int> q{};
    q.emplace(start);
    visited[start]=true;
    while(!q.empty())
    {
        int cur{q.front()};
        q.pop();
        ans.emplace_back(cur);
        for(auto& [to,weight]:graph[cur])
        {
            if(!visited[to])
            {
                q.emplace(to);
                visited[to]=true;
            }
        }
    }
    return;
}

void bfsall(vector<vector<edge>>& graph,vector<bool>& visited,vector<int>& ans)
{
    for(int i=0;i<graph.size();++i)
    {
        if(!visited[i]&&!graph[i].empty()) //
        {
            bfs(graph,visited,i,ans);
        }
    }
    return;
}

void dfs(vector<vector<edge>>& graph,vector<bool>& visited,int& start,vector<int>& ans)
{
    ans.emplace_back(start);
    visited[start]=true;
    for(auto& [to,weight]:graph[start])
    {
        if(!visited[to])
        {
            dfs(graph,visited,to,ans);
        }
    }
    return;
}

void dfsall(vector<vector<edge>>& graph,vector<bool>& visited,vector<int>& ans)
{
    for(int i=0;i<graph.size();++i)
    {
        if(!visited[i]&&!graph[i].empty()) //
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
    vector<vector<edge>> graph(nodes,vector<edge>{});
    vector<bool> visited(nodes,false);
    vector<int> ans{};
    int start{0};
    for(int i=0;i<edges;++i)
    {
        int from{},to{},weight{};
        cin >> from >> to >> weight; //
        graph[from].emplace_back(to,weight);
        graph[to].emplace_back(from,weight); //
    }
    bfs(graph,visited,start,ans);
    // bfsall(graph,visited,ans);
    // dfs(graph,visited,start,ans);
    // dfsall(graph,visited,ans);
    for(int& a:ans)
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