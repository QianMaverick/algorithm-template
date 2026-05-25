#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int min_limit{},max_limit{};
    cin >> min_limit >> max_limit;
    static random_device seed{};
    static mt19937 engine(seed());
    uniform_int_distribution<int> scope(min_limit,max_limit); // [1,100]
    // uniform_real_distribution<double> scope(min_limit,max_limit); // [1,100)
    int num{scope(engine)};
    // double num{scope(engine)};
    cout << num << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}