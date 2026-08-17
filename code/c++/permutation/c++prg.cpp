#include <bits/stdc++.h>
using namespace std;

vector<int> temp;

void dfs(vector<int> nums,vector<bool> visit)
{
    if(temp.size()==nums.size())
    {
        for(int i:temp)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for(int i=0;i<nums.size();++i)
    {
        if(visit[i])
        {
            continue;
        }
        if(i>0&&nums[i]==nums[i-1]&&!visit[i-1])
        {
            continue;
        }
        visit[i]=true;
        temp.emplace_back(nums[i]);
        dfs(nums,visit);
        temp.pop_back();
        visit[i]=false;
    }
    return;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<bool> visit(n,false);
    for(int& i:nums)
    {
        cin >> i;
    }
    sort(nums.begin(),nums.end(),less<int>());
    dfs(nums,visit);
    return;
}

signed main()
{
    solve();
    return 0;
}