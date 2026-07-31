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
            cout << sk.top() << " ";
        }
        else
        {
            cout << -1 << " ";
        }
        sk.emplace(i);
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}