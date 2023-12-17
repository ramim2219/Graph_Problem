#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool detect(int src,vector<int> adj[],int vis[])
{
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjacentNode:adj[node])
        {
            if(!vis[adjacentNode])
            {
                vis[adjacentNode]=1;
                q.push({adjacentNode,node});
            }
            else if(parent!=adjacentNode)
            {
                return true;
            }
        }
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
            if(detect(i,adj,vis))return true;
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
    if(isCycle(n,a))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
