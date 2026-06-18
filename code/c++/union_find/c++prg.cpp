#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> fa;
    vector<int> sz;
    DSU(int n)
    {
        fa.resize(n,0);
        sz.resize(n,1);
        for(int i=0;i<n;++i)
        {
            fa[i]=i;
        }
    }
    int find(int x)
    {
        int root=x;
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
    bool merge(int x,int y)
    {
        x=find(x);
        y=find(y);
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
};

void solve()
{
    int n;
    cin >> n;
    DSU dsu(n);
    int a,b;
    cin >> a >> b;
    dsu.find(a);
    dsu.merge(a,b);
    return;
}

signed main()
{
    solve();
    return 0;
}