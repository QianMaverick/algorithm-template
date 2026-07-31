#include <bits/stdc++.h>
using namespace std;

int binary_multiplication(int a,int b)
{
    int num=0;
    while(b!=0)
    {
        if(b%2==1)
        {
            num=num+a;
        }
        a=a+a;
        b=b/2;
    }
    return num;
}

void solve()
{
    int a,b;
    cin >> a >> b;
    cout << binary_multiplication(a,b) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}