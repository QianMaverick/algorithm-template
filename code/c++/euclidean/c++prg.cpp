#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    return (b==0)?a:gcd(b,a%b);
}

int lcm(int a,int b)
{
    return abs(a*b)/gcd(a,b);
}

void solve()
{
    int a{},b{};
    cin >> a >> b;
    cout << gcd(a,b) << endl;
    cout << lcm(a,b) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}