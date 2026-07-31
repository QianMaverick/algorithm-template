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

int cab(int a,int b,int mod,vector<int> facs)
{
    if(b<0||a<b)
    {
        return 0;
    }
    return facs[a]*binary_exponentiation(facs[b],mod-2,mod)%mod*binary_exponentiation(facs[a-b],mod-2,mod)%mod;
}

int lucas(int a,int b,int mod,vector<int> facs)
{
    if(a==0)
    {
        return 1;
    }
    return cab(a%mod,b%mod,mod,facs)*lucas(a/mod,b/mod,mod,facs)%mod;
}

void solve()
{
    int a,b,mod;
    cin >> a >> b >> mod;
    vector<int> facs(mod+1,0);
    facs[0]=1;
    for(int i=1;i<=mod;++i)
    {
        facs[i]=facs[i-1]*i%mod;
    }
    cout << lucas(a,b,mod,facs) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}