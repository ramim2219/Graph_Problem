#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void bfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis)
{
    int n=grid.size();
    int m=grid[0].size();
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int drow=-1;drow<=1;drow++)
        {
            for(int dcol=-1;dcol<=1;dcol++)
            {
                int nrow=row+drow;
                int ncol=col+dcol;
                if(ncol>=0 && ncol<m && nrow>=0 && nrow<n && grid[nrow][ncol]==1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
int numOfIselands(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    int cnt=0;
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<m;col++)
        {
            if(vis[row][col]==0 && grid[row][col]==1)
            {
                cnt++;
                bfs(row,col,grid,vis);
            }
        }
    }
    return cnt;
}
int main()
{
    int n,m,x;
    cin>>n>>m;
    vector<vector<int>>grid(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>x;
            grid[i].push_back(x);
        }
    }
    int ans = numOfIselands(grid);
    cout<<ans<<endl;
    return 0;
}
