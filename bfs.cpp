#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
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
    int vis[n]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push(node);
        for(auto it:a[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return 0;
}
