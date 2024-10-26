#include<bits/stdc++.h>
using namespace std;
int r,c;
char a [20][20];
bool vis [20][20];
vector<pair<int,int>> p = {{-1,-1},{-1,1},{1,-1},{1,1}};
bool valid(int pi,int pr){
    if(pi<0 || pi>=r || pr<0 || pr>=c) return false;
    else return true;
}
void DFS(int si,int sj)
{
    cout<<si<<" "<<sj<<endl;
    vis[si][sj]=true;
    for(int i = 0 ; i<4; i++){
        int ci = si+p[i].first;
        int cj = sj+p[i].second;
        if(valid(ci,cj)==true && vis[ci][cj] == false)
        {
            DFS(ci,cj);
        }
    }
}
int main (){
    cin>>r>>c;
    for(int i = 0 ; i<r; i++)
    {
        for(int j = 0 ; j<c ; j++)
        {
            cin>>a[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;
    memset(vis,false,sizeof(vis));
    DFS(si,sj);
    return 0;
}