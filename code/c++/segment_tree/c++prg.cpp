#include <bits/stdc++.h>
using namespace std;

int maxn=1e5+10;
vector<int> tree(maxn*4,0);
vector<int> lazy(maxn*4,0);
vector<int> nums(maxn,0);

void up(int x)
{
    tree[x]=tree[x*2]+tree[x*2+1];
    return;
}

void down(int x,int l,int r)
{
    if(lazy[x]==0)
    {
        return;
    }
    int m=(l+r)/2;
    int u=x*2;
    int v=x*2+1;
    tree[u]=tree[u]+lazy[x]*(m-l+1);
    lazy[u]=lazy[u]+lazy[x];
    tree[v]=tree[v]+lazy[x]*(r-m);
    lazy[v]=lazy[v]+lazy[x];
    lazy[x]=0;
    return;
}

void build(int x,int l,int r)
{
    if(l==r)
    {
        tree[x]=nums[l];
        lazy[x]=0;
        return;
    }
    int m=(l+r)/2;
    int u=x*2;
    int v=x*2+1;
    build(u,l,m);
    build(v,m+1,r);
    up(x);
    lazy[x]=0;
    return;
}

void add(int x,int l,int r,int a,int b,int num)
{
    if(b<l||r<a)
    {
        return;
    }
    if(a<=l&&r<=b)
    {
        tree[x]=tree[x]+num*(r-l+1);
        lazy[x]=lazy[x]+num;
        return;
    }
    down(x,l,r);
    int m=(l+r)/2;
    int u=x*2;
    int v=x*2+1;
    add(u,l,m,a,b,num);
    add(v,m+1,r,a,b,num);
    up(x);
    return;
}

int sum(int x,int l,int r,int a,int b)
{
    if(b<l||r<a)
    {
        return 0;
    }
    if(a<=l&&r<=b)
    {
        return tree[x];
    }
    down(x,l,r);
    int m=(l+r)/2;
    int u=x*2;
    int v=x*2+1;
    return sum(u,l,m,a,b)+sum(v,m+1,r,a,b);
}

void solve()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> nums[i];
    }
    build(1,1,n);
    int a,b,c;
    cin >> a >> b >> c;
    add(1,1,n,a,b,c);
    cin >> a >> b;
    cout << sum(1,1,n,a,b) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}