#include <bits/stdc++.h>
using namespace std;

void test()
{
    return;
}

void solve()
{
    auto start=chrono::high_resolution_clock::now();
    test();
    auto end=chrono::high_resolution_clock::now();
    auto ns=chrono::duration_cast<chrono::nanoseconds>(end-start);
    auto us=chrono::duration_cast<chrono::microseconds>(end-start);
    auto ms=chrono::duration_cast<chrono::milliseconds>(end-start);
    auto s=chrono::duration_cast<chrono::seconds>(end-start);
    cout << ns.count() << "ns" << endl;
    cout << us.count() << "us" << endl;
    cout << ms.count() << "ms" << endl;
    cout << s.count()  << "s" << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}