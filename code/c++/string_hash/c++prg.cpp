#include <bits/stdc++.h>
using namespace std;
int a=13331;
int b=1e9+7;

void solve()
{
    string s1,s2;
    cin >> s1 >> s2;
    int n=s1.size();
    int m=s2.size();
    if(n!=m)
    {
        cout << false << endl;
        return;
    }
    vector<int> num1(n+1,0),pow1(n+1,1);
    vector<int> num2(m+1,0),pow2(m+1,1);
    for(int i=1;i<=n;++i)
    {
        num1[i]=(num1[i-1]*a+s1[i-1])%b;
        num2[i]=(num2[i-1]*a+s2[i-1])%b;
        pow1[i]=pow1[i-1]*a%b;
        pow2[i]=pow2[i-1]*a%b;
    }
    int hash1=(num1[n]-num1[0]*pow1[n]%b+b)%b;
    int hash2=(num2[m]-num2[0]*pow2[n]%b+b)%b;
    if(hash1==hash2)
    {
        cout << true << endl;
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