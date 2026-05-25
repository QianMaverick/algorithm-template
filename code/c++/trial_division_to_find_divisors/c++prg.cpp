#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int num{};
    cin >> num;
    vector<int> nums{};
    for(int i=1;i<=num/i;++i)
    {
        if(num%i==0)
        {
            nums.emplace_back(i);
            if(i!=num/i)
            {
                nums.emplace_back(num/i);
            }
        }
    }
    sort(nums.begin(),nums.end(),less<int>());
    for(int& n:nums)
    {
        cout << n << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}