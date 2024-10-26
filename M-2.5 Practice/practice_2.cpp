#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool visited [1005];
int level[1005];
void BFS(int src){

    queue<int> q;
    q.push(src);
    visited[src]=true;
    level[src]=0;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        for(auto child : v[par]){
            if(!visited[child])
            {
                q.push(child);
                visited[child]=true;
                level[child]=level[par]+1;
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
     memset(visited,false,sizeof(visited));
     memset(level,-1,sizeof(level));
    int l;
    cin>>l;
    vector<int>pr;
    BFS(0);
    for(int i = 0 ; i<n ; i++)
    {
        if(level[i]==l)pr.push_back(i);
    }
    // sort(pr.rbegin(),pr.rend());
    reverse(pr.begin(),pr.end());
    for(int val : pr) cout<<val<<" ";
    return 0;
}