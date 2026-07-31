#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string p,s;
    cin >> p >> s;
    vector<int> nexts(p.size());
    vector<int> ans;
    for(int i=1,j=0;i<p.size();++i)
    {
        while(j!=0&&p[i]!=p[j])
        {
            j=nexts[j-1];
        }
        if(p[i]==p[j])
        {
            ++j;
        }
        nexts[i]=j;
    }
    for(int i=0,j=0;i<s.size();++i)
    {
        while(j!=0&&s[i]!=p[j])
        {
            j=nexts[j-1];
        }
        if(s[i]==p[j])
        {
            ++j;
        }
        if(j==p.size())
        {
            ans.emplace_back(i-p.size()+1);
            j=nexts[j-1];
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