#include <bits/stdc++.h>
using namespace std;

class union_find
{
public:
    vector<int> fa;
    vector<int> sz;
    union_find(int n)
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
        while(root!=fa[root])
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
    union_find uf(n);
    int a,b;
    cin >> a >> b;
    uf.find(a);
    uf.merge(a,b);
    return;
}

signed main()
{
    solve();
    return 0;
}