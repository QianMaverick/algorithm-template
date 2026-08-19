#include <bits/stdc++.h>
using namespace std;

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
    int n;
    cin >> n;
    vector<ca> nums(n);
    for(ca& i:nums)
    {
        cin >> i.a >> i.b;
    }
    sort(nums.begin(),nums.end(),com());
    priority_queue<int,vector<int>,greater<int>> hp;
    for(ca i:nums)
    {
        if(hp.empty()||i.a<=hp.top())
        {
            hp.emplace(i.b);
        }
        else
        {
            hp.pop();
            hp.emplace(i.b);
        }
    }
    cout << hp.size() << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}