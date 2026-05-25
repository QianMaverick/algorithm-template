#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int val{};
    tree* left{};
    tree* right{};
    tree():val(0),left(nullptr),right(nullptr){}
    tree(int v):val(v),left(nullptr),right(nullptr){}
    tree(int v,tree* l):val(v),left(l),right(nullptr){}
    tree(int v,tree* l,tree* r):val(v),left(l),right(r){}
};

void deleteTree(tree* root)
{
    if(!root)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
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
    queue<tree*> q{};
    q.emplace(root);
    while(!q.empty())
    {
        tree* cur{q.front()};
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
    tree* root{new tree(nums[start++])};
    queue<tree*> q{};
    q.emplace(root);
    while(!q.empty()&&start<nums.size())
    {
        tree* cur{q.front()};
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
    tree* root{new tree(nums[start++])};
    root->left=creatdfs(nums,start);
    root->right=creatdfs(nums,start);
    return root;
}

void solve()
{
    int nodes{};
    cin >> nodes;
    vector<int> nums(nodes,{});
    vector<int> ans{};
    int start{0};
    for(int& n:nums)
    {
        cin >> n; //
    }
    tree* root{creatbfs(nums,start)};
    bfs(root,ans);
    // tree* root{creatdfs(nums,start)};
    // dfs(root,ans);
    for(int& a:ans)
    {
        cout << a << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    solve();
    return 0;
}