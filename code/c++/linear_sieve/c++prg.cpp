#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<bool> nums(n+1,true);
    vector<int> temp;
    nums[0]=false;
    nums[1]=false;
    for(int i=2;i<=n;++i)
    {
        if(nums[i])
        {
            temp.emplace_back(i);
        }
        for(int j:temp)
        {
            if(i*j>n)
            {
                break;
            }
            nums[i*j]=false;
            if(i%j==0)
            {
                break;
            }
        }
    }
    for(int i:temp)
    {
        cout << i << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}