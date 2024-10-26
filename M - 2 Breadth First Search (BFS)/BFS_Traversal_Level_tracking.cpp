#include<bits/stdc++.h>
using namespace std;
vector<int> v [1005];
bool visited [1005];
int level[1005];
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
    int src;
    cin>>src;
    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    BFS(src);
    cout<<endl;
    // for(int i = 0; i<=node ; i++){
    //     cout<< i <<" "<<level[i]<<endl;
    // }
    cout<<level[1];
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