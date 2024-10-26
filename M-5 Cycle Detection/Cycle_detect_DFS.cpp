#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>v[N];
bool vis[N];
bool pathVisit[N];
bool ans=false;
void DFS(int src)
{
    vis[src]=true;
    pathVisit[src]=true;
    for(int child : v[src])
    {
        if(pathVisit[child])
        {
            ans=true;
        }
        if(vis[child]==false)
        {
            DFS(child);
        }
    }
    pathVisit[src]=false;
}
int main (){
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a , b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i = 0 ; i<n ; i++)
    {
        if(vis[i]==false)
        {
            DFS(i);
        }
    }
    if(ans) cout<<"Cycle Detect";
    else cout<<"No Cycle";
    return 0;
}