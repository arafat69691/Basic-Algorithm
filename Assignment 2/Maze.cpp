
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char mz[N][N];
bool visit[N][N];
pair<int,int> parent[1005][1005];


int n, m;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && mz[i][j] != '#' && !visit[i][j];
}

void BFS(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visit[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;

        if (mz[a][b] == 'D')
        {
            while (a != si || b != sj)
            {
                if (mz[a][b] != 'D' && mz[a][b] != 'R')
                {
                    mz[a][b] = 'X';
                }
                int pa = parent[a][b].first;
                int pb = parent[a][b].second;
                a = pa;
                b = pb;
            }
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj))
            {
                q.push({ci, cj});


                visit[ci][cj] = true;
                parent[ci][cj] = {a, b};
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int ci, cj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mz[i][j];
            if (mz[i][j] == 'R')
            {
                ci = i;
                cj = j;
            }
        }
    }
    memset(visit, false, sizeof(visit));
 BFS(ci, cj);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mz[i][j];
        }
        cout << endl;
    }

    return 0;
}