#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int num{};
    cin >> num;
    if(num==1)
    {
        cout << false << endl;
        return;
    }
    for(int i=2;i<=num/i;++i)
    {
        if(num%i==0)
        {
            cout << false << endl;
            return;
        }
    }
    cout << true << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}