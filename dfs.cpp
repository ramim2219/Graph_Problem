#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
void dfs(int node,vector<int>adj[],int vis[],vector<int>&ls)
{
    vis[node]=1;
    ls.push_back(node);
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,ls);
        }
    }
}
int main()
{
    fast;
    int n,m,u,v;
    cin>>n>>m;
    vector<int>adj[m+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ls;
    int vis[n]={0};
    int start;
    cout<<"Enter node : ";
    cin>>start;
    dfs(start,adj,vis,ls);
    for(auto it:ls)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
