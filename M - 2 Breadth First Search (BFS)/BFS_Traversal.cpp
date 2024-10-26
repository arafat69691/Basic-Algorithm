/*
5 6
0 1
1 2
0 4
1 3
2 0
3 4
0
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>v [1005];
bool visit[1005];

void bfs(int src ){
    queue<int>q;
    q.push(src);
    visit[src]=true;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        cout<<par<<endl;
        for(int i = 0 ; i<v[par].size();i++){
            int child = v[par][i];
            if(visit[child]==false){
                q.push(child);
                visit[child]=true;
            }
        }
    }
}
int main (){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src;
    cin>>src;
    memset(visit,false,sizeof(visit));
    bfs(src  );
    return 0;
}