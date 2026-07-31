#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int& i:nums)
    {
        cin >> i;
    }
    stack<int> sk;
    for(int i:nums)
    {
        while(!sk.empty()&&i<=sk.top())
        {
            sk.pop();
        }
        if(!sk.empty())
        {
            cout << sk.top() << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        sk.emplace(i);
    }
    return;
}

signed main()
{
    solve();
    return 0;
}