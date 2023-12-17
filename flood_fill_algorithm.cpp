#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void dfs(int row,int col,vector<vector<int>>&image,int newColor,vector<vector<int>>&ans,int iniColor)
{
    ans[row][col]=newColor;
    int n=image.size();
    int m=image[0].size();
    int delRow[]={-1,0,1,0};
    int delCol[]={0,-1,0,1};
    for(int i=0;i<4;i++)
    {
        int nrow=row-delRow[i];
        int ncol=col-delCol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
           && ans[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
        {
            dfs(nrow,ncol,image,newColor,ans,iniColor);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int newColor,vector<vector<int>>& ans)
{
    int iniColor=image[sr][sc];
    dfs(sr,sc,image,newColor,ans,iniColor);
    return ans;
}
int main()
{
    int newColor,n,m,x,sr,sc;
    cout<<"Enter row and col: ";
    cin>>n>>m;
    cout<<"Enter new Color: ";
    cin>>newColor;
    cout<<"Enter sr and sc: ";
    cin>>sr>>sc;
    vector<vector<int>>image(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>x;
            image[i].push_back(x);
        }
    }
    vector<vector<int>>ans=image;
    floodFill(image,sr,sc,newColor,ans);
    cout<<"Before Operation:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"After Operation"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
