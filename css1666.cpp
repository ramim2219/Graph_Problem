#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
void dfs(int node,vector<int>adj[],int vis[])
{
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis);
        }
    }
}
int main()
{
    fast;
    int n,m,u,v;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>ans;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int vis[n+1]={0};
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            ans.push_back(i);
            dfs(i,adj,vis);
        }
    }
    if(ans.size()==1)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<ans.size()-1<<endl;
        for(int i=0;i<ans.size();i++)
        {
            if(i>0)cout<<ans[i-1]<<" "<<ans[i]<<endl;
        }
    }
    return 0;
}
