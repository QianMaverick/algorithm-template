#include <bits/stdc++.h>
using namespace std;

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

int find2(int x,vector<int>& fa)
{
    if(fa[x]!=x)
    {
        fa[x]=find2(fa[x],fa);
    }
    return fa[x];
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

bool union2(int x,int y,vector<int>& fa,vector<int>& rk)
{
    x=find2(x,fa);
    y=find2(y,fa);
    if(x==y)
    {
        return false;
    }
    if(rk[x]<rk[y])
    {
        swap(x,y);
    }
    fa[y]=x;
    if(rk[x]==rk[y])
    {
        ++rk[x];
    }
    return true;
}

void solve1()
{
    int n;
    cin >> n;
    vector<int> fa(n);
    vector<int> sz(n,1);
    for(int i=0;i<n;++i)
    {
        fa[i]=i;
    }
    int x;
    cin >> x;
    cout << find1(x,fa) << endl;
    int y,z;
    cin >> y >> z;
    union1(y,z,fa,sz);
    return;
}

void solve2()
{
    int n;
    cin >> n;
    vector<int> fa(n);
    vector<int> rk(n,0);
    for(int i=0;i<n;++i)
    {
        fa[i]=i;
    }
    int x;
    cin >> x;
    cout << find2(x,fa) << endl;
    int y,z;
    cin >> y >> z;
    union2(y,z,fa,rk);
    return;
}

signed main()
{
    solve1();
    solve2();
    return 0;
}