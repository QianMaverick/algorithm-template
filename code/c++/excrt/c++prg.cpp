#include <bits/stdc++.h>
using namespace std;

int exgcd(int a,int b,int& x,int& y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int gcd=exgcd(b,a%b,y,x);
    y=y-a/b*x;
    return gcd;
}

void solve()
{
    int n;
    cin >> n;
    int a1,m1;
    cin >> a1 >> m1;
    for(int i=1;i<n;++i)
    {
        int a2,m2,k1,k2;
        cin >> a2 >> m2;
        int d=exgcd(a1,a2,k1,k2);
        if((m2-m1)%d==0)
        {
            k1=(k1*(m2-m1)/d%(a2/d)+(a2/d))%(a2/d);
            m1=m1+k1*a1;
            a1=a1/d*a2;
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << m1 << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}