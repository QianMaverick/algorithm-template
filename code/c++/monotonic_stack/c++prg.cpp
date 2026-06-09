#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    stack<int> nums;
    while(n--)
    {
        int num;
        cin >> num;
        while(!nums.empty()&&num<=nums.top())
        {
            nums.pop();
        }
        if(!nums.empty())
        {
            cout << nums.top() << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        nums.push(num);
    }
    return;
}

signed main()
{
    solve();
    return 0;
}