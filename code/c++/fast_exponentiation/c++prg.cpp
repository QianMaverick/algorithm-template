#include <bits/stdc++.h>
using namespace std;

int fast_exponentiation(int a,int b)
{
    int num{1};
    while(b)
    {
        if(b&1)
        {
            num=num*a;
        }
        a=a*a;
        b>>=1;
    }
    return num;
}

void solve()
{
    int a{},b{};
    cin >> a >> b;
    cout << fast_exponentiation(a,b) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}