#include <bits/stdc++.h>
using namespace std;

vector<int> temp;

void dfs(int x,int m,vector<int> nums)
{
    if(temp.size()==m)
    {
        for(int i:temp)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for(int i=x;i<nums.size()+temp.size()-m+1;++i)
    {
        temp.emplace_back(nums[i]);
        dfs(i+1,m,nums);
        temp.pop_back();
    }
    return;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int& i:nums)
    {
        cin >> i;
    }
    dfs(0,m,nums);
    return;
}

signed main()
{
    solve();
    return 0;
}