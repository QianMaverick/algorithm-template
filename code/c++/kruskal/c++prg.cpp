#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::max()/2;

class edge
{
public:
    int u;
    int v;
    int w;
    edge(int u,int v,int w):u(u),v(v),w(w){}
};

class compare
{
public:
    bool operator()(edge a,edge b)
    {
        return a.w<b.w;
    }
};

int find1(int x,vector<int>& fa)
{
    int root=x;
    while(fa[root]!=root)
    {
        root=fa[root];
    }
    while(fa[x]!=root)
    {
        int temp=fa[x];
        fa[x]=root;
        x=temp;
    }
    return root;
}

bool union1(int x,int y,vector<int>& fa,vector<int>& sz)
{
    x=find1(x,fa);
    y=find1(y,fa);
    if(x==y)
    {
        return false;
    }
    if(sz[x]<sz[y])
    {
        swap(x,y);
    }
    fa[y]=x;
    sz[x]=sz[x]+sz[y];
    return true;
}

int kruskal(vector<edge>& edges,int n)
{
    sort(edges.begin(),edges.end(),compare());
    vector<int> fa(n,0);
    vector<int> sz(n,1);
    for(int i=0;i<n;++i)
    {
        fa[i]=i;
    }
    int sum=0;
    int num=0;
    for(edge cur:edges)
    {
        if(union1(cur.u,cur.v,fa,sz))
        {
            sum=sum+cur.w;
            ++num;
            if(num==n-1)
            {
                break;
            }
        }
    }
    if(num==n-1)
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
    vector<edge> edges;
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edges.emplace_back(u,v,w);
    }
    int num=kruskal(edges,n);
    cout << num << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}