#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& nums,int& l,int& r)
{
    if(l>=r)
    {
        return;
    }
    int m=(l+r)/2;
    if(nums[l]>nums[m])
    {
        swap(nums[l],nums[m]);
    }
    if(nums[m]>nums[r])
    {
        swap(nums[m],nums[r]);
    }
    if(nums[l]>nums[m])
    {
        swap(nums[l],nums[m]);
    }
    int i=l;
    int j=r;
    int num=nums[m];
    while(i<=j)
    {
        while(i<=j&&nums[i]<num)
        {
            ++i;
        }
        while(i<=j&&nums[j]>num)
        {
            --j;
        }
        if(i<=j)
        {
            swap(nums[i++],nums[j--]);
        }
    }
    quick_sort(nums,l,j);
    quick_sort(nums,i,r);
    return;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int& i:nums)
    {
        cin >> i;
    }
    int l=0;
    int r=nums.size()-1;
    quick_sort(nums,l,r);
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