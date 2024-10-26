#include<bits/stdc++.h>
using namespace std;
vector<int> v [1005];
bool visited [1005];
int level[1005];
int parent[1005];
void BFS(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src]=0;
    while(!q.empty())
    {
         
        int par = q.front();
        q.pop();

        for(int child : v[par])
        {
            if(visited[child]==false)
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[par]+1;
                parent[child]=par;
            }
        }
    }

}
int main (){
    int node , edge;
    cin>> node>>edge;
    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);

    }
    int src,des;
    cin>>src>>des;
    
    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    BFS(src);
    int x = des;
    vector<int> path;
    while(x!=-1)
    {
        path.push_back(x);
         x=parent[x];
       
    }
    reverse(path.begin(),path.end());
    int c;
    // for(int val : path) cout<<val<<" ";
    for(int i = 0 ; i<path.size() ; i++){
        c = i;
    }
    cout<<c;
   
    return 0;
}

/*
7 8
0 1
1 2
0 4
1 3
2 0
3 4
1 5
3 6
0
*/