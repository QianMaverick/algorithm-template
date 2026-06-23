#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b;
    cin >> a >> b;
    static random_device seed;
    static mt19937 engine(seed());
    uniform_int_distribution<int> scope(a,b); // [a,b]
    int num=scope(engine);
    cout << num << endl;
    uniform_real_distribution<double> scope(a,b); // [a,b)
    double num=scope(engine);
    cout << num << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}