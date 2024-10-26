#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
bool vis[N];

void DFS(int src)
{
    cout<<src<<" ";
    vis[src]=true;
    for(int child : v[src])
    {
        if(vis[child]== false)
        {
            DFS(child);
        }
    }
}

int main (){
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    DFS(0);
    return 0;
}