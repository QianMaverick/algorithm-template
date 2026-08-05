#include <bits/stdc++.h>
using namespace std;
using ty=unsigned long long;

void solve()
{
    string str;
    cin >> str;
    ty n=str.size();
    ty base1=131,mod1=1e9+7;
    ty base2=13331,mod2=1e9+8;
    vector<ty> num1(n+1,0),pow1(n+1,1);
    vector<ty> num2(n+1,0),pow2(n+1,1);
    for(ty i=1;i<=n;++i)
    {
        num1[i]=(num1[i-1]*base1+str[i-1])%mod1;
        num2[i]=(num2[i-1]*base2+str[i-1])%mod2;
        pow1[i]=pow1[i-1]*base1%mod1;
        pow2[i]=pow2[i-1]*base2%mod2;
    }
    ty l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if((num1[r1]-num1[l1-1]*pow1[r1-l1+1]%mod1+mod1)%mod1==(num1[r2]-num1[l2-1]*pow1[r2-l2+1]%mod1+mod1)%mod1)
    {
        if((num2[r1]-num2[l1-1]*pow2[r1-l1+1]%mod2+mod2)%mod2==(num2[r2]-num2[l2-1]*pow2[r2-l2+1]%mod2+mod2)%mod2)
        {
            cout << true << endl;
        }
        else
        {
            cout << false << endl;
        }
    }
    else
    {
        cout << false << endl;
    }
    return;
}

signed main()
{
    solve();
    return 0;
}