#include <bits/stdc++.h>
using namespace std;

int binary_search(int num,vector<int> nums)
{
    int l=0;
    int r=nums.size()-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(nums[m]==num)
        {
            return m;
        }
        if(nums[m]<num)
        {
            l=m+1;
        }
        if(nums[m]>num)
        {
            r=m-1;
        }
    }
    return -1;
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
    int num;
    cin >> num;
    cout << binary_search(num,nums) << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}