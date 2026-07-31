#include <bits/stdc++.h>
using namespace std;

int binary_exponentiation(int a,int b,int mod)
{
    int num=1;
    while(b!=0)
    {
        if(b%2==1)
        {
            num=num*a%mod;
        }
        a=a*a%mod;
        b=b/2;
    }
    return num;
}

void solve()
{
    int a,b;
    cin >> a >> b;
    cout << binary_exponentiation(a,b-2,b) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}