#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool dfs(int node,int parent,vector<int> adj[],int vis[])
{
    vis[node]=1;
    for(auto adjacentNode:adj[node])
    {
        if(!vis[adjacentNode])
        {
            if(dfs(adjacentNode,node,adj,vis)==true)return true;
        }
        else if(parent!=adjacentNode)return true;
    }
    return false;
}
bool isCycle(int V,vector<int>adj[])
{
    int vis[V]={0};
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1,adj,vis)==true)return true;
        }
    }
    return false;
}
int main()
{
    fast;
    int n,m,u,v;
    cin>>n>>m;
    vector<int>a[m+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if(isCycle(n,a)==true)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
