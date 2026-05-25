#include <bits/stdc++.h>
using namespace std;

int find(int& x,vector<int>& fa)
{
    int root{x};
    while(fa[root]!=root)
    {
        root=fa[root];
    }
    while(fa[x]!=root)
    {
        int temp{fa[x]};
        fa[x]=root;
        x=temp;
    }
    return root;
}

void merge(int& x,int& y,vector<int>& fa,vector<int>& sz)
{
    x=find(x,fa);
    y=find(y,fa);
    if(x==y)
    {
        return;
    }
    if(sz[x]<sz[y])
    {
        swap(x,y);
    }
    fa[y]=x;
    sz[x]=sz[x]+sz[y];
    return;
}

void solve()
{
    int n{};
    cin >> n;
    vector<int> fa(n+1,0);
    vector<int> sz(n+1,1);
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
    }
    int a{},b{},c{};
    cin >> a >> b >> c;
    find(a,fa);
    merge(b,c,fa,sz);
    return;
}

signed main()
{
    solve();
    return 0;
}