#include <bits/stdc++.h>
using namespace std;

class trie
{
public:
    unordered_map<char,trie*> rank;
    int num;
    trie():rank(),num(){}
};

void solve()
{
    trie* root=new trie();
    string str;
    cin >> str;
    trie* cur=root;
    for(char s:str)
    {
        if(cur->rank.find(s)==cur->rank.end())
        {
            cur->rank[s]=new trie();
        }
        cur=cur->rank[s];
    }
    ++cur->num;
    bool flag=true;
    for(char s:str)
    {
        if(cur->rank.find(s)!=cur->rank.end())
        {
            cur=cur->rank[s];
        }
        else
        {
            flag=false;
            break;
        }
    }
    if(flag==true)
    {
        cout << cur->num << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    bool flag=true;
    for(char s:str)
    {
        if(cur->rank.find(s)!=cur->rank.end())
        {
            cur=cur->rank[s];
        }
        else
        {
            flag=false;
            break;
        }
    }
    if(flag==true)
    {
        --cur->num;
    }
    return;
}

signed main()
{
    solve();
    return 0;
}