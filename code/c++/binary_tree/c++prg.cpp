#include <bits/stdc++.h>
using namespace std;

class tree
{
public:
    int val;
    tree* left;
    tree* right;
    tree(int v):val(v),left(nullptr),right(nullptr){}
};

void deletetree(tree* root)
{
    if(!root)
    {
        return;
    }
    deletetree(root->left);
    deletetree(root->right);
    delete root;
    root=nullptr;
    return;
}

void bfs(tree* root,vector<int>& ans)
{
    if(!root)
    {
        return;
    }
    queue<tree*> q;
    q.emplace(root);
    while(!q.empty())
    {
        tree* cur=q.front();
        q.pop();
        ans.emplace_back(cur->val);
        if(cur->left)
        {
            q.emplace(cur->left);
        }
        if(cur->right)
        {
            q.emplace(cur->right);
        }
    }
    return;
}

void dfs(tree* root,vector<int>& ans)
{
    if(!root)
    {
        return;
    }
    ans.emplace_back(root->val);
    dfs(root->left,ans);
    dfs(root->right,ans);
    return;
}

tree* creatbfs(vector<int> nums,int& start)
{
    if(start>=nums.size()||nums[start]==-1)
    {
        ++start;
        return nullptr;
    }
    tree* root=new tree(nums[start++]);
    queue<tree*> q;
    q.emplace(root);
    while(!q.empty()&&start<nums.size())
    {
        tree* cur=q.front();
        q.pop();
        if(start<nums.size()&&nums[start]!=-1)
        {
            cur->left=new tree(nums[start]);
            q.emplace(cur->left);
        }
        ++start;
        if(start<nums.size()&&nums[start]!=-1)
        {
            cur->right=new tree(nums[start]);
            q.emplace(cur->right);
        }
        ++start;
    }
    return root;
}

tree* creatdfs(vector<int> nums,int& start)
{
    if(start>=nums.size()||nums[start]==-1)
    {
        ++start;
        return nullptr;
    }
    tree* root=new tree(nums[start++]);
    root->left=creatdfs(nums,start);
    root->right=creatdfs(nums,start);
    return root;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i)
    {
        cin >> nums[i]; //
    }
    int start=0;
    vector<int> ans;
    tree* root=creatbfs(nums,start);
    bfs(root,ans);
    deletetree(root);
    tree* root=creatdfs(nums,start);
    dfs(root,ans);
    deletetree(root);
    for(int i=0;i<ans.size();++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}