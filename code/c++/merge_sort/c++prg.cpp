#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int>& nums,int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int m{(l+r)/2};
    merge_sort(nums,l,m);
    merge_sort(nums,m+1,r);
    int i{l};
    int j{m+1};
    vector<int> temp{};
    while(i<=m&&j<=r)
    {
        if(nums[i]<nums[j])
        {
            temp.emplace_back(nums[i++]);
        }
        else
        {
            temp.emplace_back(nums[j++]);
        }
    }
    while(i<=m)
    {
        temp.emplace_back(nums[i++]);
    }
    while(j<=r)
    {
        temp.emplace_back(nums[j++]);
    }
    for(int i=0;i<temp.size();++i)
    {
        nums[l+i]=temp[i];
    }
    temp.clear();
    return;
}

void solve()
{
    int n{};
    cin >> n;
    vector<int> nums(n,0);
    for(int& i:nums)
    {
        cin >> i;
    }
    merge_sort(nums,0,nums.size()-1);
    for(int i:nums)
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