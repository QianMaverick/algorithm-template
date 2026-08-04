#include <bits/stdc++.h>
using namespace std;

int lowbit(int x)
{
    return (x&-x);
}

void add(int i,int num,vector<int>& nums)
{
    int n=nums.size();
    for(;i<=n;i=i+lowbit(i))
    {
        nums[i]=nums[i]+num;
    }
    return;
}

int sum(int i,vector<int>& nums)
{
    int sum=0;
    for(;i>=1;i=i-lowbit(i))
    {
        sum=sum+nums[i];
    }
    return sum;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> nums(n+1,0);
    for(int i=1;i<=n;++i)
    {
        int num;
        cin >> num;
        add(i,num,nums);
    }
    int i,num;
    cin >> i >> num;
    add(i,num,nums);
    int l,r;
    cin >> l >> r;
    cout << sum(r,nums)-sum(l-1,nums) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}