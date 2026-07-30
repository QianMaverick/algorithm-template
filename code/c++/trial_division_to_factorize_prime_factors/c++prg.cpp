#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int num;
    cin >> num;
    map<int,int> nums;
    for(int i=2;i<=num/i;++i)
    {
        while(num%i==0)
        {
            ++nums[i];
            num=num/i;
        }
    }
    if(num>1)
    {
        ++nums[num];
    }
    for(pair<int,int> i:nums)
    {
        cout << i .first << " " << i.second << endl;
    }
    return;
}

signed main()
{
    solve();
    return 0;
}