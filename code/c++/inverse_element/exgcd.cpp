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
    int a,b,x,y;
    cin >> a >> b;
    exgcd(a,b,x,y);
    x=(x%b+b)%b;
    cout << x << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}