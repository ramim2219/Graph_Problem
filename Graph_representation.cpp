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
    for(int i=0;i<m;i++)
    {
        for (int j=0;j<a[i].size();j++)
        {
            cout<<i<<" "<<a[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
