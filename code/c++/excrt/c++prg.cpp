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
        int a2,m2,x,y;
        cin >> a2 >> m2;
        int gcd=exgcd(a1,a2,x,y);
        if((m2-m1)%gcd==0)
        {
            x=((x*(m2-m1)/gcd)%(a2/gcd)+(a2/gcd))%(a2/gcd);
            m1=m1+a1*x;
            a1=a1*a2/gcd;
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