#include<bits/stdc++.h>
using namespace std;
vector<int> v[10005];
bool vis[10005];
void BFS(int src ){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        cout<<par<<endl;
        for(int i = 0 ; i<v[par].size();i++){
            int child = v[par][i];
            if(vis[child]==false){
                q.push(child);
                vis[child]=true;
            }
        }
    }
}
void connection(int src) {
    if (v[src].empty()) {
        cout << "-1" << endl;
        return;
    }
    
    vector<int> val = v[src];
    sort(val.begin(), val.end(), greater<int>());
    
    for (int v : val) {
        cout << v << " ";
    }
    cout << endl;
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
    int q;
    cin >>q;
    while(q--){
    int src;
    cin>>src;
    connection(src);
    }
    return 0;
}