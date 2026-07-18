#include <bits/stdc++.h>
using namespace std;

int find(int x,vector<int>& fa)
{
    int root=x;
    while(root!=fa[root])
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

bool merge(int x,int y,vector<int>& fa,vector<int>& sz)
{
    x=find(x,fa);
    y=find(y,fa);
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

void solve()
{
    int n;
    cin >> n;
    vector<int> fa(n,0);
    vector<int> sz(n,1);
    for(int i=0;i<n;++i)
    {
        fa[i]=i;
    }
    int a,b;
    cin >> a >> b;
    find(a,fa);
    find(b,fa);
    merge(a,b,fa,sz);
    return;
}

signed main()
{
    solve();
    return 0;
}