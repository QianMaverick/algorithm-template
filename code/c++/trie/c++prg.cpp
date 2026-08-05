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
    int n;
    cin >> n;
    trie* root=new trie();
    for(int i=0;i<n;++i)
    {
        char ch;
        string str;
        cin >> ch >> str;
        trie* cur=root;
        if(ch=='i')
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
        else if(ch=='f')
        {
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
        }
        else if(ch=='d')
        {
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
        }
    }
    return;
}

signed main()
{
    solve();
    return 0;
}