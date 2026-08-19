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
        return a.b<b.b;
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
    vector<ca> temp(1,nums[0]);
    for(int i=1;i<n;++i)
    {
        if(temp.back().b<nums[i].a)
        {
            temp.emplace_back(nums[i]);
        }
    }
    cout << temp.size() << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}