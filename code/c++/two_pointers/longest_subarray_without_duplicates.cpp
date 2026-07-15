#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
    cin >> n;
	vector<int> nums(n);
	for(int& i:nums)
    {
        cin >> i;
    }
    int ans=0;
	map<int,int> count;
	for(int i=0,j=0;j<n;++j)
	{
		++count[nums[j]];
		while(count[nums[j]]>1)
		{
			--count[nums[i++]];
		}
		ans=max(ans,j-i+1);
	}
	cout << ans << endl;
	return;
}

signed main()
{
	solve();
	return 0;
}