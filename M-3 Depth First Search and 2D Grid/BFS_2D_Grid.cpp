#include<bits/stdc++.h>
using namespace std;
int r,c;
char a [20][20];
bool vis[20][20];
int dis [20][20];
vector<pair<int,int>> p = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool valid(int i , int j)
{
    if(i<0 || i>=r || j<0 || j>=c) return false;
    return true;
}
void BFS(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis [si][sj]=true;
    dis[si][sj]=0;
    while(!q.empty())
    {
        pair <int,int> par=q.front();
        q.pop();
       for(int i = 0 ; i<4; i++){
            int ci = par.first+p[i].first;
            int cj = par.second + p[i].second;
            if(valid(ci,cj)==true && vis[ci][cj]== false){
                q.push({ci,cj});
                vis[ci][cj]=true;
                dis[ci][cj]=dis[par.first][par.second]+1;
            }
       }
    }
}
int main (){
    cin>>r>>c;
    for(int i = 0 ; i<r; i++){
        for(int j =0 ;j<c ; j++)
        {
            cin>>a[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    BFS(si,sj);
    cout<<dis[2][3];
    return 0;
}