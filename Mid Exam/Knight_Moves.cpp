#include <bits/stdc++.h>
using namespace std;
int n, m;
bool visited[105][105];
int dis[105][105];
vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
bool valid(int a, int b)
{
    if (a < 0 || a >= n || b < 0 || b >= m)
      {
          return false;
      }
   else  return true;
}

void DFS(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    dis[i][j] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        
        for (int i = 0; i < 8; i++)
        {
            int cj = parent.second + d[i].second;

            int ci = parent.first + d[i].first;

            if (valid(ci, cj) && !visited[ci][cj])
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                dis[ci][cj] = dis[parent.first][parent.second] + 1;
            }
        }
    }
}
int main()
{
    int q;
    cin >> q;
    while (q--)
    {

        cin >> n >> m;

        memset(visited, false, sizeof(visited));
        memset(dis, -1, sizeof(dis));
        int si, sj;
        cin >> si >> sj;
        DFS(si, sj);
        int di, dj;
        cin >> di >> dj;
        cout << dis[di][dj] << endl;
    }
    return 0;
}