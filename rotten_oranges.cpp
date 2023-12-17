#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
//int bfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis,int cnt)
//{
//    int n=grid.size();
//    int m=grid[0].size();
//    vis[row][col]=1;
//    grid[row][col]=2;
//    queue<pair<int,int>>q;
//    q.push({row,col});
//    int delRow[]={-1,0,1,0};
//    int delCol[]={0,-1,0,1};
//    while(!q.empty())
//    {
//        int row=q.front().first;
//        int col=q.front().second;
//        q.pop();
//        bool ans=false;
//        for(int i=0;i<4;i++)
//        {
//            int nrow=row+delRow[i];
//            int ncol=col+delCol[i];
//            if(ncol>=0 && ncol<m && nrow>=0 && nrow<n && grid[nrow][ncol]==1 && !vis[nrow][ncol])
//            {
//                ans=true;
//                vis[nrow][ncol]=1;
//                grid[nrow][ncol]=2;
//                q.push({nrow,ncol});
//            }
//        }
//        if(ans)
//        {
//            cnt++;
//        }
//    }
//    return cnt;
//}
int rotten_oranges(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i,j},0});
                vis[i][j]=2;
            }
        }
    }
    int tm=0;
    int delRow[]={-1,0,1,0};
    int delCol[]={0,-1,0,1};
    while(!q.empty())
    {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        tm=max(tm,t);
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=r+delRow[i];
            int ncol=c+delCol[i];
            if(ncol>=0 && ncol<m && nrow>=0 &&
               nrow<n && grid[nrow][ncol]==1 &&
               vis[nrow][ncol]!=2)
            {
                vis[nrow][ncol]=1;
                grid[nrow][ncol]=2;
                q.push({{nrow,ncol},t+1});
            }
        }
    }
    return tm;
}
int main()
{
    int n,m,x;
    cout<<"Enter row and column : ";
    cin>>n>>m;
    cout<<"Enter the matrix: "<<endl;
    vector<vector<int>>grid(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>x;
            grid[i].push_back(x);
        }
    }
    int cnt=rotten_oranges(grid);
    cout<<cnt<<endl;
    return 0;
}
