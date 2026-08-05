#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s,p;
    cin >> s >> p;
    int n=s.size();
    int m=p.size();
    vector<int> nexs(m);
    vector<int> ans;
    for(int i=1,j=0;i<m;++i)
    {
        while(j!=0&&p[i]!=p[j])
        {
            j=nexs[j-1];
        }
        if(p[i]==p[j])
        {
            ++j;
        }
        nexs[i]=j;
    }
    for(int i=0,j=0;i<n;++i)
    {
        while(j!=0&&s[i]!=p[j])
        {
            j=nexs[j-1];
        }
        if(s[i]==p[j])
        {
            ++j;
        }
        if(j==m)
        {
            ans.emplace_back(i-m+1);
            j=nexs[j-1];
        }
    }
    for(int i:ans)
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