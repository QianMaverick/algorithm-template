#include <bits/stdc++.h>
using namespace std;

void solve1()
{
    int a,b;
    cin >> a >> b;
    static random_device sed;
    static mt19937 eng(sed());
    uniform_int_distribution<int> scp(a,b);
    cout << scp(eng) << endl;
    return;
}

void solve2()
{
    double a,b;
    cin >> a >> b;
    static random_device sed;
    static mt19937 eng(sed());
    uniform_real_distribution<double> scp(a,b);
    cout << scp(eng) << endl;
    return;
}

signed main()
{
    solve1();
    solve2();
    return 0;
}