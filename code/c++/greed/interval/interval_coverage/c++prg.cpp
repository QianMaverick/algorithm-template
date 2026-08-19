#include <bits/stdc++.h>
using namespace std;
int inf=numeric_limits<int>::min()/2;

class ca
{
public:
    int a;
    int b;
};

class com
{
public:
    bool operator()(ca a,ca b)
    {
        return a.a<b.a;
    }
};

void solve()
{
    int l,r;
    cin >> l >> r;
    int n;
    cin >> n;
    vector<ca> nums(n);
    for(ca& i:nums)
    {
        cin >> i.a >> i.b;
    }
    sort(nums.begin(),nums.end(),com());
    int i=0;
    int sum=0;
    while(i<n)
    {
        int num=inf;
        while(i<n&&nums[i].a<=l)
        {
            num=max(num,nums[i++].b);
        }
        if(num<l)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            l=num;
            ++sum;
        }
        if(l>=r)
        {
            cout << sum << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}