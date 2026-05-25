#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int num{};
    cin >> num;
    map<int,int> nums{};
    for(int i=2;i<=num/i;++i)
    {
        while(num%i==0)
        {
            ++nums[i];
            num/=i;
        }
    }
    if(num>1)
    {
        ++nums[num];
    }
    for(auto& [i,j]:nums)
    {
        cout << i << " " << j << endl;
    }
    return;
}

signed main()
{
    solve();
    return 0;
}