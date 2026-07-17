#include <bits/stdc++.h>
using namespace std;
int mod=1e6+7;

int binary_expinentiation(int a,int b)
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
    int n=max(a,b);
    vector<int> facs(n+1,0);
    facs[0]=1;
    for(int i=1;i<=n;++i)
    {
        facs[i]=facs[i-1]*i%mod;
    }
    vector<int> invs(n+1,0);
    invs[n]=binary_expinentiation(facs[n],mod-2);
    for(int i=n-1;i>=0;--i)
    {
        invs[i]=invs[i+1]*(i+1)%mod;
    }
    if(a>=b)
    {
        cout << ((facs[a]*invs[b])%mod*invs[a-b])%mod << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return;
}

signed main()
{
    solve();
    return 0;
}