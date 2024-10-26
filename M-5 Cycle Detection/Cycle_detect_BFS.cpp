#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>v [N];
bool vis[N];
int parent[N];
bool ans = false;


void BFS(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        
        for(int child : v[par])

        {
            if(vis[child]==true && parent[par]!=child){
                ans = true;
                
            }
            if(!vis[child]){
                vis[child]=true;
                parent[child] =par;
                q.push(child);
                
            }
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
    memset(parent,-1,sizeof(parent));
    for(int i = 0 ; i<n ; i++){
        if(vis[i]==false)
        {
            BFS(i);
        }
    }
    if(ans) cout<<"Cycle found";
    else cout<<"Cycle not found";
    return 0;
}