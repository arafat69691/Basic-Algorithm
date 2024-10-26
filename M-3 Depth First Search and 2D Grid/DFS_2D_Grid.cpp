#include <bits/stdc++.h>
using namespace std;
int r, c;
char a[20][20];
bool vis[20][20];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// vector<pair<int,int>> d = {{-1,-1},{-1,1},{1,-1},{1,1}};
bool Valid(int i, int j)
{
    if(i<0 || i>=r || j<0 || j>=c) return false;
    return true;
}
void DFS(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (Valid(ci, cj) == true && vis[ci][cj] == false)
        {
            DFS(ci, cj);
        }
        // cout<<ci<<" "<<cj<<endl;
    }
}
int main()
{
    
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    DFS(si, sj);
    return 0;
}