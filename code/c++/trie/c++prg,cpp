#include <bits/stdc++.h>
using namespace std;

struct trie
{
    unordered_map<char,trie*> rank;
    int num;
    trie():rank(),num(){}
};

void solve()
{
    int n;
    cin >> n;
    trie* root=new trie();
    for(int i=0;i<n;++i)
    {
        char ch;
        string str;
        cin >> ch >> str;
        trie* cur=root;
        if(ch=='I')
        {
            for(char s:str)
            {
                if(cur->rank.find(s)==cur->rank.end())
                {
                    cur->rank[s]=new trie();
                }
                cur=cur->rank[s];
            }
            ++cur->num;
        }
        else if(ch=='F')
        {
            for(char s:str)
            {
                if(cur->rank.find(s)!=cur->rank.end())
                {
                    cur=cur->rank[s];
                }
                else
                {
                    cout << 0 << endl;
                    goto end;
                }
            }
            cout << cur->num << endl;
            end:;
        }
        else if(ch=='D')
        {
            for(char s:str)
            {
                if(cur->rank.find(s)==cur->rank.end())
                {
                    cur->rank[s]=new trie();
                }
                cur=cur->rank[s];
            }
            --cur->num;
        }
    }
    return;
}

signed main()
{
    solve();
    return 0;
}